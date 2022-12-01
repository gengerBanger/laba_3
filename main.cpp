#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
using namespace std;
void XY(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    this_thread :: sleep_for(chrono :: milliseconds (400));
}
void null_arr (int n, int *arr){
    for(int *parr = arr, i = 1;  i <= n * n; i++, parr++){
        *parr =  0;
    }
}
void arr_out (int n, int *arr){
    for(int *parr = arr, i = 1;  i <= n * n; i++, parr++){
        if (*parr < 10){
            cout <<" ";
        }

        cout << *parr <<" ";

        if (i % n == 0){
            cout << "\n";
        }
    }
}
void spiral (int n, int *arr){
    int *parr = arr, i = 1 ,pop = 1, x = 0, y = 0;
    while (i <= n * n){
        for(int j = 1; j <= n - pop; j++){
            *parr = i;
            cout << *parr;
            if (j != n) XY(x += 3, y);
            i++;
            parr++;
        }
        for(int j = 1; j <= n - pop; j++){
            *parr = i;
            cout << *parr;
            XY(x, ++y);
            i++;
            parr += n;
        }
        for(int j = 1; j <= n - pop; j++){
            *parr = i;
            cout << *parr;
            XY(x -= 3, y);
            i++;
            parr--;
        }
        for(int j = 1; j <= n - pop; j++){
            *parr = i;
            i++;
            if(j == n - pop){
                cout << *parr;
                XY(x += 3,y);
                parr++;
            }
            else{
                cout << *parr;
                XY(x,--y);
                parr -= n;
            }
        }
        pop += 2 ;
    }
    XY(0,n + 2);
}
void snake(int n, int *arr){
    int *parr = arr, i = 1, x = 0, y = 0;
    while(i <= n * n){
        for(int j = 1; j <= n; j++){
            *parr = i;
            i++;
            if(j == n){
                cout << *parr;
                XY(x += 3,y);
                parr++;
            }
            else{
                cout << *parr;
                XY(x,++y);
                parr += n;
            }
        }
        for(int j = 1; j <= n; j++){
            *parr = i;
            i++;
            if(j == n){
                cout << *parr;
                XY(x += 3,y);
                parr++;
            }
            else{
                cout << *parr;
                XY(x,--y);
                parr -= n;
            }
        }
    }
    XY(0,n + 2);
}
void permutationA(int n, int *arr){
    int buff_1,buff_2,buff_3, *parr = arr;
    for(int j = 0; j < n / 2;j++){
        for (int g = 0; g < n / 2; g++){
            buff_1 = *(parr + n / 2);
            *(parr + n / 2) = *parr;
            parr += n / 2;
            buff_2 = *(parr + (n / 2) * n);
            *(parr + (n / 2) * n) = buff_1;
            parr += (n / 2) * n;
            buff_3 = *(parr - n / 2);
            *(parr - n / 2) = buff_2;
            parr -= n / 2;
            *(parr - (n / 2) * n) = buff_3;
            parr -= (n / 2) * n;
            if (g != n / 2 - 1) parr++;
        }
        parr += (n / 2 + 1);
    }
    arr_out(n, arr);
}
void permutationB(int n, int *arr){
    int *parr = arr;
    for(int j = 0; j < n / 2;j++){
        for (int g = 0; g < n / 2; g++){
            swap(*parr,*(parr + (n / 2) * n + n / 2 ));
            if (g != n / 2 - 1) parr++;
        }
        parr += (n / 2 + 1);
    }
    parr = arr + n / 2;
    for(int j = 0; j < n / 2;j++){
        for (int g = 0; g < n / 2; g++){
            swap(*parr,*(parr + (n / 2) * n - n / 2 ));
            if (g != n / 2 - 1) parr++;
        }
        parr += (n / 2 + 1);
    }
    arr_out(n, arr);
}
void permutationC(int n, int *arr) {
    int *parr = arr;
    for(int j = 0; j < n / 2;j++){
        for (int g = 0; g < n / 2; g++){
            swap(*parr,*(parr + (n / 2) * n ));
            if (g != n / 2 - 1) parr++;
        }
        parr += (n / 2 + 1);
    }
    parr = arr + n / 2;
    for(int j = 0; j < n / 2;j++){
        for (int g = 0; g < n / 2; g++){
            swap(*parr,*(parr + (n / 2) * n ));
            if (g != n / 2 - 1) parr++;
        }
        parr += (n / 2 + 1);
    }
    arr_out(n, arr);
}
void permutationD(int n, int *arr) {
    int *parr = arr;
    for(int j = 0; j < n / 2;j++){
        for (int g = 0; g < n / 2; g++){
            swap(*parr,*(parr + (n / 2)));
            if (g != n / 2 - 1) parr++;
        }
        parr += (n / 2 + 1);
    }
    parr = arr + (n / 2) * n;
    for(int j = 0; j < n / 2;j++){
        for (int g = 0; g < n / 2; g++){
            swap(*parr,*(parr + (n / 2) ));
            if (g != n / 2 - 1) parr++;
        }
        parr += (n / 2 + 1);
    }
    arr_out(n, arr);
}

void arr_sort(int *arr, int *end, int n){

    for (int *parr_1 = arr + 1; parr_1 <= end; parr_1++){
        for (int *parr = parr_1;parr > arr;parr-- ){
            if (*parr < *(parr - 1)) {
                swap(*parr,*(parr - 1));
            }
        }

    }
    arr_out(n,arr);
}
void op_plus(int *arr,int *end, int n,  int value){
    for (int *parr = arr; parr <= end; parr++){
        *parr += value;
    }
    arr_out(n, arr);
}
void op_minus(int *arr,int *end, int n,  int value){
    for (int *parr = arr; parr <= end; parr++){
        *parr -= value;
    }
    arr_out(n, arr);
}
void op_multiplication(int *arr,int *end, int n,  int value){
    for (int *parr = arr; parr <= end; parr++){
        *parr *= value;
    }
    arr_out(n, arr);
}
void op_division(int *arr,int *end, int n,  int value){
    for (int *parr = arr; parr <= end; parr++){
        *parr /= value;
    }
    arr_out(n, arr);
}
int main(){
    int n;
    char letter;
    cin >> n;
    int arr[n][n];
    null_arr(n, &arr[0][0]);

    repeat1:
    cout << "Choose output format :" <<"\n" <<"a) Spiral"<<"\n" <<"b) Sneak"<<"\n";
    cin >> letter;
    switch (letter){
        case 'a':
            if (system("CLS")) system("clear");
            spiral(n, &arr[0][0]);
            cout << "\n" << "\n";
            break;
        case 'b':
            if (system("CLS")) system("clear");
            snake(n, &arr[0][0]);
            cout << "\n" << "\n";
            break;
        default:
            cout <<"\t" << "Error" << "\n";
            cin.clear();
            while(cin.get() != '\n');
            goto repeat1;
    }
    repeat2:
    cout << "Choose permutation :" << "\n" << "1) a"<< "\n"<< "2) b"<< "\n"<< "3) c"<< "\n"<< "4) d"<< "\n";
    cin >> letter;
    switch (letter){
        case 'a':
            cout <<'\n';
            permutationA(n,&arr[0][0]);
            cout <<'\n';
            break;
        case 'b':
            cout <<'\n';
            permutationB(n,&arr[0][0]);
            cout <<'\n';
            break;
        case 'c':
            cout <<'\n';
            permutationC(n,&arr[0][0]);
            cout <<'\n';
            break;
        case 'd':
            cout <<'\n';
            permutationD(n,&arr[0][0]);
            cout <<'\n';
            break;
        default:
            cout <<'\n';
            cout <<"\t" << "Error" << "\n";
            cout <<'\n';
            goto repeat2;
    }
    int *end = &arr[0][0] + n * n - 1;
    cout << "Sorted array :" << '\n'<< '\n';
    arr_sort(&arr[0][0],end,n);

    cout << "\n";

    int value;
    repeat3 :
    cout << "Enter value"<<"\n";
    cin >> value;
    cout << "Enter operation"<< "\n";
    cin >> letter;
    switch (letter){
        case '+':
            op_plus(&arr[0][0],end , n ,value);
            break;
        case '-':
            op_minus(&arr[0][0],end , n ,value);
            break;
        case '*':
            op_multiplication(&arr[0][0],end , n ,value);
            break;
        case '/':
            op_division(&arr[0][0],end , n ,value);
            break;
        default:
            cout <<'\n';
            cout <<"\t" << "Error" << "\n";
            cout <<'\n';
            goto repeat3;
    }
    system("pause");
    return 0;
}
