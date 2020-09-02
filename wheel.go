package otto

import (
	"sync"
)

// 时间轮实现方法 每一圈用时60秒，每个刻度5秒，转完12时间度

// 推送任务用gRpc包裹

// 任务也需要取消机制

// Round    第几圈触发
// At       在那个刻度触发
// Work     触发任务
type Queue struct {
	_name  string
	Round  int
	At     int
	Status int8
	Loop   bool
	Work   func() bool
}

// wheel struct
// Ruling 共有多少个刻度
// Elapse 刻度间耗时
type Wheels struct {
	Ruling int
	Elapse int
	Queen  []*Queue
	sync.RWMutex
}

func NewWheels(ruling, elapse int) *Wheels {
	wheels := new(Wheels)
	queue := make([]*Queue, ruling)
	wheels.Queen = queue
	wheels.Elapse = elapse
	return wheels
}

func (wheels *Wheels) Run() {

}

func (wheels *Wheels) Put(loop bool, delayTime int64,fn  func() bool) {

}
func (wheels *Wheels) Cancel() {

}
