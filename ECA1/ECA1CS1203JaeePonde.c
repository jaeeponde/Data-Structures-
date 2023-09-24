// #include <stdio.h>


// // QuickPerm algorithm to generate permutations
// void quickPerm(int* arr, int n) {
//     // Initialize the p array to 0
//     int p[n];
//     for(int i = 0; i < n; i++) {
//         p[i] = 0;
//     }
    
//     // Print the initial array
//     printArray(arr, n);

//     int i = 1; // Index to track current position
//     while(i < n) {
//         if (p[i] < i) {
//             // Check for even or odd i to choose the swap position
//             int j = (i % 2 == 0) ? 0 : p[i];
            
//             // Swap arr[i] and arr[j]
//             swap(arr, i, j);
            
//             // Print the new permutation
//             printArray(arr, n);
            
//             // Increment p[i] and reset i
//             p[i]++;
//             i = 1;
//         } else {
//             // Reset p[i] and increment i
//             p[i] = 0;
//             i++;
//         }
//     }
// }

// int main() {
//     int n; int arr[];
//     printf("Enter a number for n<=8 \n");
//     scanf("%d",&n);
//     for(i=0;i<=n;i++){
//         arr[i]=i+1;
//     }
//     quickPerm(arr, n);
//     return 0;
// }
