#include<stdio.h>

int main()
{
    // print in one line 
   printf("HSC is knocking on the door\n"); 
   // print in multiple lines
   printf("Hello \n world \n");
//    int -> 1, 2, 3, -4, 5  (2^31 )-1
//    double ->  -1, -0.32, -1.44, 0, 1, 1.22
//    char -> 'a', 'b', 'c', 'D'
//    long long int -> 1e18  (2^18)-1
//    unsigned int -> 1, 2, 3, 4, 5
//    unsigned long long int -> positive 1e19
    int a = 3, b = 14 ; 
    int ans = a*a ; 
    printf("%d is the square\n",ans);
    int diya = a*b ; // simillarly plus, minus, multipication, division 
    printf("%d this is the multipication\n",diya); 
    int remainder = b%a; // remainder of b/a  (%) 
    printf("%d this is the remainder\n",remainder);
    // taking input 
    int x, y ; 
    scanf("%d %d",&x, &y);
    printf("x is %d\nY is %d\n",x,y);

    //If else 
    // == means comparison 
    if(x%2 == 0){
        printf("%d this is an even number\n",x);
    }
    else{
        printf("%d is an odd number\n",x);
    }
    // multiple if else block 
    if( x <= 10){
        printf("small\n");
    }
    else if (x <=20 && x>10){
        printf("medium\n");
    }
    else{
        printf("Large\n");
    }

    // or condition 
    if(x%2 ==0 || x%3 == 0)
    {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    // and condition 
    if(x%2 ==0 && x%3 == 0)
    {
        printf("YES for and\n");
    }
    else{
        printf("NO for and\n");
    }
    // multiple if else 
    if(x%2 == 0 && x%3 == 0)
    {
        printf("divisible by both \n");
    }
    else if (x%2 == 0){
        printf("only divisible by 2\n");
    }
    else if(x%3 == 0){
        printf("Only divisible by 3\n");
    }
    else{
        printf("Not divisible by any\n");
    }

    //Loop
    // for( initiallly only once executed ; check this condition every time ; execute this statement everytime ){

    // }
    for(int i =1 ; i<=100 ; i++ )
    {
        if( i%2 == 0 ){
            printf("%d ",i);
        }
    }
    printf("\n\n\n");
    int n = 100;
    // while loop 
    while(n >1){
        printf("%d ",n);
        n = n/2 ; 
    }
    printf("\n");
    int sum = 0 ; 
    for(int i = 0 ; i<= x ; i++)
    {
        sum  = sum + i*i;
    }
    
    printf("%d\n", sum);
    // do while loop
    int currentNumber = 1 ; 
    int result = 0 ; 
    do{
        result = result + currentNumber*currentNumber ; 
        currentNumber++ ; 
    }
    while(currentNumber <= x);
    printf("%d\n", result);

    // algorithm
    /*
        1. initialize a variable i to 1 
        2. check if I <= x, if not then go to 6 
        3. increase sum by i*i 
        4. increment i by 1 
        5 . go to step 2
        6 print the result
    */



   // june 7 

   // print all odd numbers from 1 to n 
// n has already been declared so just taking input 
   scanf("%d",&n);
   int summation = 0 ;
   for(int i = 1; i <= n ; i++)
   {
        if(i % 2 == 1)
        {
            // if it comes to here, it means that this is an odd number 
            summation = summation + i ; 

            printf("%d ",i);  
        }
   }
   printf("\n");
   printf(" the summation of odd numbers is %d\n", summation);

    // print 1 , 4, 9 , 16 , 25 .. ans so on upto N 
    summation = 0 ; 
    for(int i = 1 ; i*i <= n ; i++)
    {
        summation = summation + i*i;
        printf("%d ", i*i);
    }
    printf("the square summation is %d\n", summation);

}

// hf = K(max) + W 
// given energy = (electron energy / nibriti vibob) + workFunction 
// given energy - workFunction = (electron energy / nibriti vibob) 

// 5V 
// electronCharge * 5 ; 

// ---->>>>>> E(k)             (++    <<---- ---)


// 10 eV 
// 10 * e * 1 = J   

// eV 
//     electron Charge * voltage 



// TP^ (1-& / & ) = PT ^ (&/1-&)
