object Solution {
    def solution(schedules: Vector[Int], timelogs: Vector[Vector[Int]], startday: Int): Int = {
        val validday = (0 until 7).collect{
            case i if ((startday + i) % 7 >= 1 && (startday + i) % 7 <= 5) => i
        }
        
        val add10min = schedules.map{
            case sche => 
            if (sche % 100 >= 50) (sche + 50) % 2400
            else sche + 10
        }
        
        val count = add10min.zip(timelogs).count{
            case (sche, logs) => validday.forall(i => logs(i) <= sche)
        }
        
        return count
    }
}