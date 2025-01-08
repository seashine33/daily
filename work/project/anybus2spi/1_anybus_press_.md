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