object Solution {
    def solution(n: Int): String = {
        val ans = (1 to n).map{
            case i => 
                if(i % 2 == 1) "수";
                else "박";
        }.mkString("")
        return ans
    }
}