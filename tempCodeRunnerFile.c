select(int array[],int size){
//     int key,i,j;
//     for(i = 1 ; i < size ; i++){ // 삽입정렬 하기위해 queue[1]부터 비교하기 위해 반복문 돌리기 시작
//         key = array[i];               // 키값을 설정해 키 값의 앞부분을 비교
//         for(j = i - 1; j >= 0; j--){  // 키값의 바로 앞부분부터 queue[0]까지 비교 반복문 시작
//             if(array[j] > key){       // queue[j] 값이 키값보다 크면 
//                 array[j + 1] = array[j]; //queue[j+1]에 queue[j]값을 넣어준다.
//             }
//             else{                     // 같은 수들이 배열에 겹쳐지지 않게 queue[j] 값이 작거나 같으면 바뀌지 않게 break를 걸어준다.
//                 break;
//             }
//         }
//         array[j+1] = key;  // 반복문을 나오게 된다면, j값은 반복문에서 계속 작아졌고, 반복문이 끝났을 때 j값 기준으로 앞에 값자리가 key값이 들어갈 자리이므로 이렇게 공식 선언
//     }
//     return array;
// }