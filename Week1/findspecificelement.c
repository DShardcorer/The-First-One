#include<stdio.h>
#include<math.h>
double avg;
double closestnumber( double array[],int size){
    double sum=0;
    for(int i=0;i<size;i++){
        sum+=array[i];
    }
    avg= sum/size;
    double mindiff=99999;
    int mindiffindex = 0;
    for(int i=0;i<size;i++){
        if(fabs(array[i]-avg)< mindiff){
            mindiff=array[i];
            mindiffindex=i;
        }
    }return array[mindiffindex];
}
int main() {
    int size = 5;
    double array[5] = {1.2, 3.4, 2.1, 5.6, 4.3};
    double closest = closestnumber(array, size);
    printf("Closest number to the average: %f, Average: %f", closest, avg);
    return 0;
}