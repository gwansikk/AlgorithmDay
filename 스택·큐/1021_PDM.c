// O(n^2)

#include <stdio.h>

void reset_arr(int N, int array[]){
    for(int i = 1; i < N + 1; i++){ // 배열 초기화
        array[i] = i;
    }
}

int main() {
    int arr[51] = {0,};
    int size = 0; // 총 배열의 크기
    int size_temp = 0; // 중간중간 줄어드는 배열의 크기
    int half_size = 0; // 배열의 이동방향 결정 변수
    int cycle = 0; // 추출해야하는 숫자의 갯수
    int number = 0; // 추출되는 숫자
    int cnt = 0; // 배열이 총 움직인 횟수 => 최종 도출되는 답
    
    scanf("%d %d",&size, &cycle);
    size_temp = size;
    
    reset_arr(size, arr);
    
    for(int i = 0; i < cycle; i++){
        scanf("%d", &number);
        int temp = arr[number];

        // 배열을 왼쪽으로 움직일지, 오른쪽으로 움직일지 계산
        if(size_temp % 2 == 0) // 짝수
            half_size = size_temp / 2;
        else // 홀수
            half_size = size_temp / 2 + 1;
            
        if(arr[number] <= half_size){ // 배열이 왼쪽으로 갈때
            // move_left();
            for(int j = 1; j < size + 1; j++){
                if(arr[j] < temp){
                   arr[j] = arr[j] + size_temp - temp;
                }
                else{
                    arr[j] = arr[j] - temp;
                }
            }
            cnt += temp - 1;
            size_temp -= 1;
        }
        else if(temp > half_size){ // 배열이 오른쪽으로 갈때
            for (int j = 1; j < size + 1; j++) {
                if(arr[j] > temp){
                    arr[j] = arr[j] - temp;
                }
                else{
                     arr[j] = arr[j] + size_temp - temp;
                }
            }
            cnt += size_temp - temp + 1;
            size_temp -= 1;
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
