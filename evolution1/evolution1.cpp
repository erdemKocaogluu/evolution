
    #include "evolution1.h"



    #include <iostream>
    #include <random>


    string evolution1:: mutation(string str) {
        int length = str.length() ;
        int r = 1 + (rand() / (RAND_MAX + 1.0)) * length;


        r = r -1 ;


        int howManyTimes = r ;


        for (int i = 0 ; i < howManyTimes ; i++ ) {

            r =  (rand() / (RAND_MAX + 1.0)) * length;





            char c = 'a' + rand() % 26;


            str[r] = c ;
            

        }


        return str ;


    }






    string evolution1 :: nextGenCreating(string str1, string str2 ) {

        string out = "" ;

                int length = str1.length() ;

        for ( int i = 0 ; i < length  ; i++ ) {

            out += " " ;


        }

        int a = 0 ;






        for ( int i = 0 ; i < length ; i++ ) {

        int r = (rand() % 2 )  ;

            if ( r == 1 ) {

                char c = str1[a++] ;

                
                out[i] = c ;




            }

            else {

                char c = str2[a++] ;

                
                out[i] = c ;



            }


        }


        return out ;



    }

    int evolution1 :: fitnessScoreLoser(string str1 , string str2 , string str3, string goal ) {


        int score1 = 0 ;
        int score2 = 0 ;
        int score3 = 0 ;


        for (int i = 0 ; i < goal.length() ; i ++ ) {

            if (str1[i] == goal[i] ) {
                score1++;
            }

            if (str2[i] == goal[i] ) {
                score2++;
            }
            
            if (str3[i] == goal[i] ) {
                score3++;




            }


        }

        int lowest = score1 ;

        if (score2 < lowest) lowest = score2 ;

        if (score3 < lowest ) lowest = score3 ;



        if (lowest == score1 ) return 1 ;

        if (lowest == score2 ) return 2 ;

        if (lowest == score3 ) return 3 ;

        return (rand() % 3) ;








    }



    int main() {

        evolution1* e = new evolution1() ;


        string goal = "bilkentseviyoruz" ;


        string str1 = "" ;


        string str2 = "" ;

        string str3 = "" ;

        for (int i = 0 ; i < goal.length() ; i++ ) {

            char c = 'a' + rand() % 26 ;

            str1 += c ;



        }



        for (int i = 0 ; i < goal.length() ; i++ ) {

            char c = 'a' + rand() % 26 ;

            str2 += c ;
            


        }



        for (int i = 0 ; i < goal.length() ; i++ ) {

            char c = 'a' + rand() % 26 ;

            str3 += c ;
            


        }



            cout << "string 1  -> " << str1 << endl ;
            cout << "string 2  -> " << str2 << endl ;
            cout << "string 3  -> " << str3 << endl ;




        while (true) {



            if (str1 == goal) break ;

            if (str2 == goal ) break ;

            if (str3 == goal ) break ;



            int a =  e->fitnessScoreLoser(str1, str2, str3, goal ) ;

            if (a == 1 ) {

                str1 = e->nextGenCreating(str2,str3) ;
                str1 = e -> mutation(str1) ;

            }


            if (a == 2 ) {

                str2 = e->nextGenCreating(str1, str3) ;
                str2 = e -> mutation(str2) ;

            }


            if (a == 3 ) {

                str3 = e->nextGenCreating(str1, str2) ;
                str3 = e -> mutation(str3) ;

            }



            cout << "string 1  -> " << str1 << endl ;
            cout << "string 2  -> " << str2 << endl ;
            cout << "string 3  -> " << str3 << endl ;






        }

        if (str1 == goal) {

            cout << str1 ;
        }


        else if (str2 == goal) {

            cout << str2 ;
        }




        else if (str3 == goal) {

            cout << str3 ;
        }



        delete e ;


    }