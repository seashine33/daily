## 第一周
### 周五： 2024.3.1，预答辩剩余23天
- 计划
  - 上午1000字。开始13854字，收尾14077字。把车辆风险场图画好了。
  - 下午，收15075字。
    - 1、把风险场图的描述写好。
    - 2、风险指标与碰撞概念的定义。

## 第二周
### 周一： 2024.3.4，预答辩剩余20天
- 计划
  - 3.3 碰撞风险评估模型完成。
- 过程
  - 我想明白了风险场分布的问题
    - 首先我自己的想法，那就是同向前车对于自车的风险场，重点在车尾，这是没问题的。
    - 然后除了跟车还有会车。例如他车从西向东以较高速度通过路口，而本车起步通过绿灯，这种情况下，他车的重点风险区域就是车辆前方。
    - 所以，车辆风险场不能简单的基于他车状态定义，而应该根据自车方位定义。
    - 晚上又跟yxh讨论了一下，我想我大概明白我原先想法的问题所在了，如果重点风险区域在车尾，那么本车处于跟车场景下，来自前车的风险会一直偏高，而且速度越快越高，这其实是不正常的，这样根本分不清什么时候是高风险时刻。真正风险高的时刻应该是前车急刹车，对应风险场会将重点风险区域转移到后方。
    - 话说回来，那如果自车身后有辆车，那岂不是自车一直处于高风险状态？实际上这明显不合理。实际开车过程中，是很少在意后车的状态的。【这确实是漏洞】
      - 风险场与实际的风险指标还是有差别，
    - 为什么匀速要中心靠前呢，车前10米和车后10米的风险肯定不同。
### 周二： 2024.3.5，预答辩剩余19天
- 计划
  - 3.3 碰撞风险评估模型完成。
- 过程
  - 把psq的风险场力部分看了，关键是自己跑了下代码，发现全是我自己的问题，所有的场景都是满足的，我之前纠结的错误其实是我只关注于车辆风险场。
  - 车辆风险场的定义，应该是他车对对应位置下的物体所产生的**压力**。
    - 如果车辆是静止不动的，那么对四周风险分布一致。
    - 如果车辆向前匀速行驶，那么该车车头10米距离物体的碰撞压力要大于车尾10米处物体。所以车辆风险场在匀速状态下的**碰撞重心**
    - 如果车辆加速度不为零，那么车辆的碰撞重心会往加速度方向偏移。
    - 如果车辆的转向角不为零，那么整个风险场会以局部坐标系为中心，往转向角方向进行偏移。
  - 最后一个疑惑：那就是车前方势场掉的速度快，车尾势场掉的快。
  - 最最后一个：碰撞风险指标如何使用？
    - 1、作为轨迹规划的评分依据（MPC）
    - 2、设定碰撞指标，

### 周三： 2024.3.6，预答辩剩余18天
- 计划
  - 3.3 邻接碰撞状态计算完成
- 过程
  - 四个变量，车长l，车宽d，两车位置θ，两车速度方向φ。
    - l/d >= 2.414
    - | φ\θ  | θ=0 | 0<θ<arctan(d/l) | θ=arctan(d/l) | arctan(d/l)<θ<90 |
      | --- | --- | --------------- | ------------- | ---------------- |
      | φ = 0 | l |
      | 0<φ<arctan(d/l) |
      | φ=arctan(d/l) |
      | arctan(d/l)<φ<90-arctan(d/l) |
      | φ = 90-arctan(d/l) |
      | 90-arctan(d/l)<φ<90 |
      | φ=90 |
    - l/d < 2.414

### 周六： 2024.3.9，预答辩剩余15天
- 计划
  - 将3.3节写完
- 过程
  - 将3.3节的内容重新梳理一下
    - 3.2节中介绍了几种来源的风险场，这一节的内容主要介绍风险场的使用，来确保系统能够有效预警。
    - 碰撞风险指标：风险场力，最大，
    - 碰撞概率
  - 基于风险场的碰撞概率画出来了
    - 效果还可以，我想表达出的概念完全表达出来了。
    - 其讨论的碰撞是360度的碰撞，也就是可以监测到碰撞来源。
    - 但，没办法表达出风险车在我前面，我风险大；我后面跟着两车，我不在意；左右有车也有一定的在意。
    - 效果就是将风险区域划分为一个个四四方方的同心矩形。 
  - 现在碰见了很大的问题
    - 我没办法把碰撞概率嵌入到我论文里面。
    - 碰撞是瞬时下的状态，讨论瞬时下状态，速度加速度等就无用，这些应该在轨迹预测里考虑，
    - 有用的只有两车相对位置、航向、转向角这些影响碰撞的状态。
    - 也就是，碰撞区域是不随车辆的状态的改变而改变的，别想通过修改车辆状态而修改碰撞区域。
    - 能随车辆状态改变而改变的是警示区域。

### 周天： 2024.3.10，预答辩剩余14天
- 总结
  - 基于**势场**的风险评估，有利于量化风险，接着做轨迹规划。
    - 需要考虑的状态：相对位置(θ,L)，相对航向角(φ)，速度(v1,v2)，加速度(a1)
  - 基于**距离**的风险评估，有利于基于距离来做碰撞评估。
    - 需要考虑的状态：相对位置(θ,L)，相对航向角(φ)
  - 势场+距离。
    - psq论文使用自车状态的方法：
      - 风险场力：风险场乘自车状态方程。得到两车之间风险的量化值。
    - 基于距离使用自车状态
      - 基于两车方位(θ,L)，本车航向，确定临界碰撞距离(L*)
      - 这种方法不考虑车辆的动态状态，就当物体都为静止物体，这样不好
      - 虽然我考虑的是当前瞬时，三秒后的瞬时，但我还是希望能体现出态势出来。
      - 例如：虽然我和前车的距离挺近的，但前车的速度或者加速度非常大，这时候就应该体现出来。
        - 提出质疑，这是当前还是预测的未来呢
        - 当前的话，应该就是碰撞本身？
        - 未来的话，【暂时搁置】
      - 首先，**碰撞环**本身是不应该修改的。
        - 基于两车的瞬时**相对位置**确定碰撞环
      - 其次，应该修改的是**概率环**。
        - 基于两车的瞬时**相对状态**确定概率环
        - 一圈圈概率环，随着风险来源车的状态的变化而发生变化。
## 第三周
### 周一： 2024.3.11，预答辩剩余10天
- 计划
  - [ ] 3.2节 基于碰撞距离的风险场模型
    - [x] 3.2.1 车辆之间的临界碰撞距离
    - [ ] 3.2.2 车辆边界的临界碰撞距离
  - [ ] 3.3节 基于碰撞距离的风险场模型
- 过程
  - 问题1：两车速度夹角90°，碰撞环确定，风险场重点区域很奇怪
    - 想风险来源车两边扩散，而不是前。
### 周二： 2024.3.12，预答辩剩余8天
- 计划
- 过程
  - 场景5中，如果车身在Y的正方向上，那么应该比对应负方向要差，总体风险区域应该在右下方。
  - 场景6中，总体风险场应该在正右方。
- 总结
  - 写到一点半，结果3.3.1节还是没有写完，还剩场景描述，不太想写了。
  - [x] 还剩七天到20号，我必须得在一天内把实验代码写好。
  - [x] 明天的任务就是3.3节写完，最好上午弄完。
  - [x] 下午把实验部分的代码调好。
  - [ ] 有空的话把3.1节给再写一遍。

### 周三： 2024.3.13，预答辩剩余7天
- 过程
  - 上午：把3.3.1写完了
  - 下午：把算法流程图画了
  - 晚上：把实验代码调好了
- 总结
  - 很是勤勉的一天

### 周四：2024.3.14，预答辩剩余7天
- 计划
  - 将第三章写完。
    - [ ] 3.1 问题分析
    - [x] 3.2.1 碰撞距离
    - [x] 3.2.2 碰撞概率
    - [x] 3.3.1 碰撞风险场
    - [x] 3.3.2 碰撞评估算法
    - [ ] 3.4.1 实验场景设计
    - [ ] 3.4.2 实验过程与结果分析
    - [ ] 3.5 本章小结
- 过程
  - 晚上大概一点四十睡觉，早上九点起来，把衣服洗了，
  - 到实验室就已经九点四十多，洗好了还得回去晾一下。
  - 把3.2.2 碰撞距离改了一下，将系数挪到P里面来了。并对文字进行修改
  - 10:42，上个厕所，回寝室收衣服
  - 11:12，回到实验室。
  - woc，我没发现60m/s，时216km/h，谁家好人开车这么离谱啊。
  - 20m/s的话大概就是72km/h，这还正常一点。