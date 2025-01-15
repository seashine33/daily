# codesys代码
* Netif_Config()
  * 链路状态发生改变时的回调函数: ethernet_link_status_updated()
  * ethernet_link_status_updated() 中会调用 udp_echoclient_connect()
  * udp_echoclient_connect() 中会创建新的udp对象, 并为udp对象绑定 目标IP 及 udp接收函数 udp_receive_callback()
* ethernetif_input() 和 udp_receive_callback() 间的关系
  * ethernetif_input() 将通过网络接口（如以太网接口）接收到的数据包传递给 LwIP 栈进行进一步的处理
  * 是网络接口层中接收数据的第一步。
  * udp_receive_callback() 是接收到 UDP 数据包时的回调函数
  * 当 LwIP 栈在 IP 层解包并解析数据包时，如果数据包是 UDP 数据包，LwIP 会调用你为 UDP 控制块（upcb）设置的接收回调函数
* Anybus2spi_GetAndSetBusData()
  * 若数据已经被读取，则返回上一帧数据
* sys_check_timeouts()
  * 在 lwip_cyclic_timers[] 中开启了: 
  * TCP 定时器: 用于管理 TCP 协议的各种定时操作，如重传超时、延时确认等。
  * IP 重组定时器: 用于处理 IP 层的数据包重组
  * ARP 定时器: 
  * DHCP 定时器
# 代码修改
## 25/1/7
* 将堆空间扩充为8KB
* 准备UDP数据时，将anybus状态机写入150字节开始的位置
* 给了一个板子给邱工测试，还有一个板子在自己手上

## 25/1/10
* 解决跑20天左右SPI数据不更新BUG
  * 原因：u32数据溢出
  * 从工厂拿回汇川、西门子PLC，准备测试4.0.0版本的Anybus2spi
  * 三种协议各测十分钟，成功则发布新版
* 解决微秒级延时，原理： 
  * 以不带IT模式HAL_TIM_Base_Start()启动启动定时器
  * 需要延时时，__HAL_TIM_SET_COUNTER()改变counter为0，等待计数值到目标延时值
  * BUG：100us以下的延时不准

## 25/1/11
* 新代码跑20小时左右，一个错都没报
* 重新进行测试：
  * 1. 网线插拔测试.
    * ✅udp网口正常通信后，插拔网线1分钟重新插入看是否还能正常通信。
  * 2. 重启测试.
    * ✅udp网口正常通信后，重启电脑，看电脑启动后网口是否正常通信。
  * 3. 关机测试
    * ✅udp网口正常通信后，关机电脑，再重新开机，看电脑启动后网口是否正常通信。
  * 4. 重启codesys软件测试
    * udp网口正常通信后，关闭codesys，重新启动codesys。验证网口通信是否正常。
    * 出错：重启工控机后通讯正常，关闭codesys再启动，SPI传输的数据全部不更新
    * 复现第二次：快速关开codesys
    * 将UDP看门狗时间调整为20s，反复1H，未出现数据不更新情况
    * [TODO]()：稳定复现
    * 分析：可能是初始化模块的时间不足的原因，将初始化时间拉长（2.5s）后，未再次出现
  * 5. 总线模块重新上电测试
    * ✅在正常进行总线通讯时，重启总线模块，通讯能否恢复；
  * 6. 休眠测试
    * ✅总线模块上电、控制器上电不进行连接，断开一晚后重新连上网线，查看通讯是否恢复正常。
  * 7. udp网口连接顺序测试
    * ✅总线模块上电和网线连接时序测试。（先上电再插网线、先插网线再上电）
  * 8. udp网口数据包格式和内容检查
    * ✅确保总线模块发送给udp端的数据包格式正确。【UDP index顺序偶发错误，频率约每天0.67次】
* 定时器最大占用时间
  * 带超时处理：运行半小时，单周期最大占用时间640us
* LwIP的timeout溢出问题
  * 加入了溢出判断
* 测试周期时间

## 25/1/14
* 从11号晚开始跑，到14号晚运行正常
* stop codesys 后 start，板子正常复位
* 开始看anybus2spi代码，捋出状态机，看是否有逻辑漏洞