

#define __int8 signed char

void x_to_y(__int8 *x){
    *x = ~(*x - 0b01) ;
}


int main(){
    __int8 x = 0b10101001; // 87
    // x_to_y(&x);
    return 0;
}