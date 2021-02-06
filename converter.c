#include <stdio.h>
#include <math.h>

int main()
{
    long long num; // For Non-hexa input.
    char in[20]; // For Hexa input.
    int option, conv, i, j; // For option taking and counters.

    printf("Type of the number you want to convert. \n 1. Binary 2. Hexa 3. Octal\nEnter : ");
    scanf("%d", &option);
    printf("\nYou want your number to get converted into. \n 1. Binary 2. Hexa 3. Octal 4. Decimal\nEnter : ");
    scanf("%d", &conv);

    int rem, index = 0; // For digit-wise calculations and output process.
    long long sum = 0; // For dealing with numeric output.
    char out[50]; // For dealing with output containing letters as well as numbers.
    
    // This array is used for conversion of binary to other system or for a conversion inside another conversion.
    int convert[] ={000, 001, 010 , 011, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111}; 
    

    switch(option)
    {
        case 1:
        printf("\nEnter your number : ");
        scanf("%lld", &num);

        switch(conv)
        {
            case 1:
            printf("Same number system.");
            break;
            
            // Binary to Hexa Conversion.
            case 2 :
            while(num != 0)
            {
                rem = num % 10000;
                for(i = 0; i < 16; i++)
                {
                    if(convert[i] == rem)
                    {
                        if(i < 10)
                        {
                            out[index] = (char)(i + 48);
                        }
                        else
                        {
                            out[index] = (char)((i - 10) + 65);
                        }
                        index++;
                        break;
                    }
                }
                num = num / 10000;
            }

            printf("Converted Number : ");
            for(i = index - 1; i >= 0; i--)
            {
                printf("%c", out[i]);
            }
            break;
            
            // Binary to Octal conversion.
            case 3:
            while(num != 0)
            {
                rem = num % 1000;
                for(i = 0; i < 8; i++)
                {
                    if(convert[i] == rem)
                    {
                        out[index] = (char)(i+48);
                        index++;
                        break;
                    }
                }
                num = num / 1000;
            }

            printf("Converted Number : ");
            for(i = index - 1; i >= 0; i--)
            {
                printf("%c", out[i]);
            }
            break;
            
            // Binary to decimal conversion.
            case 4:
            i = 1;
            while(num != 0)
            {
                rem = num % 10;
                sum = sum +(rem * i);
                i = i * 2;
                num = num/10;
            }

            printf("Converted Number : %lld", sum);
            break;

            default:
            printf("Invalid choice");
        }
        break;

        case 2:
        printf("\nEnter your number : ");
        scanf("%s",in);
      
        switch(conv)
        {
            // Hexa to Binary conversion.
            case 1:
            for(i = 0; in[i] != '\0'; i++)
            {
                switch(in[i])
                {
                    case '0':
                    printf("0000");
                    break;
                    case '1':
                    printf("0001");
                    break;
                    case '2':
                    printf("0010");
                    break;
                    case '3':
                    printf("0011");
                    break;
                    case '4':
                    printf("0100");
                    break;
                    case '5':
                    printf("0101");
                    break;
                    case '6':
                    printf("0110");
                    break;
                    case '7':
                    printf("0111");
                    break;
                    case '8':
                    printf("1000");
                    break;
                    case '9':
                    printf("1001");
                    break;
                    case 'a':
                    case 'A':
                    printf("1010");
                    break;
                    case 'b':
                    case 'B':
                    printf("1011");
                    break;
                    case 'c':
                    case 'C':
                    printf("1100");
                    break;
                    case 'd':
                    case 'D':
                    printf("1101");
                    break;
                    case 'e':
                    case 'E':
                    printf("1110");
                    break;
                    case 'f':
                    case 'F':
                    printf("1111");
                    break;
                    default:
                    printf("Invalid hexadecimal input.");
                }
            }
            
            break;
            case 2:
            printf("Same number system.");
            break;
            
            // Hexa to Octal conversion.
            case 3:
            for(i=0; in[i]!='\0'; i++)
            {
                sum = sum * 10000;
                switch(in[i])
                {
                    case '0':
                    sum = sum + 0;
                    break;
                    case '1':
                     sum = sum + 1;
                    break;
                    case '2':
                     sum = sum + 10;
                    break;
                    case '3':
                     sum = sum + 11;
                    break;
                    case '4':
                     sum = sum + 100;
                    break;
                    case '5':
                     sum = sum + 101;
                    break;
                    case '6':
                     sum = sum + 110;
                    break;
                    case '7':
                     sum = sum + 111;
                    break;
                    case '8':
                     sum = sum + 1000;
                    break;
                    case '9':
                     sum = sum + 1001;
                    break;
                    case 'a':
                    case 'A':
                     sum = sum + 1010;
                    break;
                    case 'b':
                    case 'B':
                    sum = sum + 1011;
                    break;
                    case 'c':
                    case 'C':
                     sum = sum + 1100;
                    break;
                    case 'd':
                    case 'D':
                     sum = sum + 1101;
                    break;
                    case 'e':
                    case 'E':
                     sum = sum + 1110;
                    break;
                    case 'f':
                    case 'F':
                     sum = sum + 1111;
                    break;
                    default:
                    printf("Invalid hexadecimal input.");
                }
            }
            
            while(sum != 0)
            {
                rem = sum % 1000;
                for(i = 0; i < 8; i++)
                {
                    if(convert[i] == rem)
                    {
                        out[index] = (char)(i+48);
                        index++;
                        break;
                    }
                }
                sum = sum / 1000;
            }

            printf("Converted Number : ");
            for(i = index - 1; i >= 0; i--)
            {
                printf("%c", out[i]);
            }
            break;
    
            // Hexa to decimal conversion.
            case 4:
            for(i=0; in[i]!='\0'; i++)
            {
                switch(in[i])
                {
                    case '0':
                    out[i] = (char)(0);
                    break;
                    case '1':
                    out[i] = (char)(1);
                    break;
                    case '2':
                    out[i] = (char)(2);
                    break;
                    case '3':
                    out[i] = (char)(3);
                    break;
                    case '4':
                    out[i] = (char)(4);
                    break;
                    case '5':
                    out[i] = (char)(5);
                    break;
                    case '6':
                    out[i] = (char)(6);
                    break;
                    case '7':
                    out[i] = (char)(7);
                    break;
                    case '8':
                    out[i] = (char)(8);
                    break;
                    case '9':
                    out[i] = (char)(9);
                    break;
                    case 'a':
                    case 'A':
                    out[i] = (char)(10);;
                    break;
                    case 'b':
                    case 'B':
                    out[i] = (char)(11);
                    break;
                    case 'c':
                    case 'C':
                    out[i] = (char)(12);
                    break;
                    case 'd':
                    case 'D':
                    out[i] = (char)(13);
                    break;
                    case 'e':
                    case 'E':
                    out[i] = (char)(14);
                    break;
                    case 'f':
                    case 'F':
                    out[i] = (char)(15);
                    break;
                    default:
                    printf("Invalid hexadecimal input.");
                }
            }
            j = 0;
            while(1)
            {
                sum += (((int)out[j])*pow(16, (i -1)));
                i--;
                j++;
                
                if(i == 0)
                {
                    break;
                }
            }
            printf("Converted Number : %lld", sum);
            break;

            default:
            printf("Invalid choice");
        }
        break;

        case 3:
        printf("\nEnter your number : ");
        scanf("%lld", &num);

        switch(conv)
        {
            // Octal to Binary conversion.
            case 1:
            while(num != 0)
            {
                rem = num % 10;
                out[index] = convert[rem];
                index++;
                num = num / 10;
            }
            printf("Converted Number :");
            for(i = index ; i >= 0; i--)
            {
                printf("%c", out[i]);
            }
            break;
            
            // Octal to Hexa conversion.
            case 2:
            
            while(num != 0)
            {
                rem = num % 10;
                switch(rem)
                {
                    case 0:
                    sum = sum + 0;
                    break;
                    case 1:
                     sum = sum + (1 * pow(10, i));
                    break;
                    case 2:
                     sum = sum + (10 * pow(10, i));
                    break;
                    case 3:
                     sum = sum + (11 * pow(10, i));
                    break;
                    case 4:
                     sum = sum + (100 * pow(10, i));
                    break;
                    case 5:
                     sum = sum + (101 * pow(10, i));
                    break;
                    case 6:
                     sum = sum + (110 * pow(10, i));
                    break;
                    case 7:
                     sum = sum + (111 * pow(10, i));
                }
                i = i + 3;
                num = num / 10;
            }
            
            while(sum != 0)
            {
                rem = sum % 10000;
                for(i = 0; i < 16; i++)
                {
                    if(convert[i] == rem)
                    {
                        if(i < 10)
                        {
                            out[index] = (char)(i + 48);
                        }
                        else
                        {
                            out[index] = (char)((i - 10) + 65);
                        }
                        index++;
                        break;
                    }
                }
                sum = sum / 10000;
            }

            printf("Converted Number : ");
            for(i = index - 1; i >= 0; i--)
            {
                printf("%c", out[i]);
            }
            break;
            case 3:
            printf("Same number system.");
            break;
            
            // Octal to Decimal Conversion.
            case 4:
            i = 0;
            while(num != 0)
            {
                rem = num % 10;
                sum += rem * pow(8, i);
                i++;
                num = num/10;
            }

            printf("Converted Number : ");
            printf("%lld", sum);
            break;

            default:
            printf("Invalid choice");
        }
        break;

        default:
        printf("Invalid choice");

    }
}
