void rFilter(char *s) {
    int n = strlen(s);
    char *c = s + n - 1;
    
    while (c >= s) {
        if ((*c < 'a' || *c > 'z') && (*c < 'A' || *c > 'Z'))
            *c = '_';
        else 
            break;
        c --;
    }
}