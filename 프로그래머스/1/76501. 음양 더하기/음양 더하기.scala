object Solution {
    def solution(absolutes: Vector[Int], signs: Vector[Boolean]): Int = {
        absolutes.zip(signs).map{
            case (ab, sign) =>
                if(sign)  ab
                else  -ab
        }.sum
    }
}