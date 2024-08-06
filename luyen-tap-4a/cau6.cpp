int** transpose(int** matrix, int nRows, int nCols) {
    int** matrixB = new int*[nCols];
    for(int i = 0; i < nCols; i++) {
        matrixB[i] = new int[nRows];
    } 
    
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            matrixB[j][i] = matrix[i][j];
        }
    }
    
    return matrixB;
}