void split(double num, int *int_part, double *frac_part){
    *int_part=(int)num;
    *frac_part=num-*int_part;
}
int main(){
    double num, fraction;
    int integer;
    scanf("%f", &num);
    split(num, &integer,&fraction);
}