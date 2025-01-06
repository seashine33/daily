# 简介
* 脉冲工具
# 开发过程
* 单次敲击过程约350us，过低的采样率采不到最大扭矩
* 敲击的目标越是刚性，敲击时间约短，峰值越是难以采集到。故开始时应该是以低转速、非拧紧状态为实验对象。
* ![采集结果1](image.png)
* 25NM的模拟螺栓
## ADC采样速录实验
* AD7190
  * AD7190采样速率为2K时，采样出的最大扭矩值与实际现象明显对不上，10rps时最大约0.7NM，100rps时最大约9NM。
  * AD7190采样速率最大可设置为4.8K，但感觉意义不大
* NADC24D003FA
  * 采样率最高96K，Over driving mode时才能达到
  * 普通模式下最
  * ![alt text](image-1.png)
## AD7190采样结果
* x=y/7.49*60=y*8.01，x单位rpm，y单位rps
* 20rpm = 2.47rps
  * ![整体图](image-4.png)
  * ![碰撞周期](image-5.png)
  * ![压缩时间](image-6.png)
  * ![反松](image-13.png)
* 40rpm = 4.94rps
  * ![整体图](image-8.png)
  * ![碰撞周期](image-9.png)
  * ![压缩时间](image-10.png)
  * ![反松](image-12.png)
* 60rpm = 7.41rps
  * ![整体图](image-14.png)
  * ![碰撞周期](image-15.png)
  * ![压缩时间](image-16.png)
  * ![反松](image-17.png)
* 80rpm = 9.88rps
  * ![整体图](image-18.png)
  * ![碰撞周期](image-19.png)
  * ![压缩时间](image-20.png)
  * ![反松](image-21.png)
* 80.1rpm = 10rps
  * ![alt text](image-2.png)
  * ![alt text](image-3.png)
* 100rpm = 12.33rps
  * ![整体图](image-22.png)
  * ![碰撞周期](image-23.png)
  * ![压缩时间](image-24.png)
  * ![机器反松](image-25.png)
  * ![手反松](image-26.png)
* 120rpm = 14.8rps
  * ![整体图](image-27.png)
  * ![碰撞周期](image-28.png)
  * ![峰宽](image-29.png)
  * ![手拧](image-30.png)
* 140rpm = 17.49rps
  * ![整体](image-31.png)
  * ![周期](image-32.png)
  * ![详细周期](image-33.png)
  * ![碰撞时间](image-34.png)
  * ![手拧](image-35.png)
* 160rpm = 19.975rps
  * ![整体图](image-36.png)
  * ![周期时间](image-37.png)
  * ![弹簧压缩时间](image-38.png)
  * ![周期细节](image-39.png)
  * ![峰宽](image-40.png)
## 示波器采样结果
* 填写了报告
* 20rpm = 2.47rps
* 40rpm = 4.94rps
* 60rpm = 7.41rps
* 80rpm = 9.88rps
* 100rpm = 12.33rps
* 120rpm = 14.8rps
* 160rpm = 19.975rps
## 参考专利
