#include <stdio.h>
enum Week{
    Monday=1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};
enum Month{
    January=1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main(){
    enum Week w;
    enum Month m;
    for(w=Monday;w<=Sunday;w++){
        for(m=January;m<=December;m++)
            printf("(%d,%d)",w,m);
        printf("\n");
    }
    return 0;
}