void swap(char* a, char* b){
    int temp = *a;
    *a = *b;
    *b = temp;
};
void reverse(char *s){
int n = strlen(s);
char *left = s;
char *right = s+n-1;

for(int i=0;i<n/2;i++){
    swap(left,right);
    left++;
    right--;
}
};