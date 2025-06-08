object Solution {
    def solution(name: Vector[String], yearning: Vector[Int], photo: Vector[Vector[String]]): Vector[Int] = {
        
        val score = name.zip(yearning).toMap
        
        photo.map{
            case p => p.map{
                case person => score.getOrElse(person, 0)
            }.sum
        }
    }
}