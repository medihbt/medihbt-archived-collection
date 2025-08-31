# Musys HVM -- 简单的寄存器-栈式混合虚拟机

Musys-HVM 是比 Musys IR 抽象层次高的虚拟机, 用于 Musys IR 前端的分析. 在 Musys 前端完成之前, 也作为临时的“前端”顶替使用.

与栈式的 JVM 和寄存器式的 Dalvik 不同, Musys-HVM 既有栈空间也有寄存器空间 -- 寄存器空间可以方便 IR 的生成以及优化, 栈空间可以存放数组、结构体等等内容. 
