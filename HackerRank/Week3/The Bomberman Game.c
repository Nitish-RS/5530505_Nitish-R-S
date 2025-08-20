int R = grid_count;
    int C = (int)strlen(grid[0]);
    *result_count = R;

    if (n % 2 == 0) {
        char** out = (char**)malloc(R * sizeof(char*));
        for (int i = 0; i < R; i++) {
            out[i] = (char*)malloc(C + 1);
            memset(out[i], 'O', C);
            out[i][C] = '\0';
        }
        return out;
    }

    char** out = (char**)malloc(R * sizeof(char*));
    for (int i = 0; i < R; i++) { out[i] = (char*)malloc(C + 1); out[i][C] = '\0'; }

    if (n == 1) {
        for (int i = 0; i < R; i++) memcpy(out[i], grid[i], C);
        return out;
    }

    int* kill = (int*)calloc((size_t)R * C, sizeof(int));
    const int di[4] = {-1, 1, 0, 0};
    const int dj[4] = {0, 0, -1, 1};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'O') {
                int idx = i * C + j;
                kill[idx] = 1;
                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k], nj = j + dj[k];
                    if ((unsigned)ni < (unsigned)R && (unsigned)nj < (unsigned)C) kill[ni * C + nj] = 1;
                }
            }
        }
    }

    char** A = (char**)malloc(R * sizeof(char*));
    for (int i = 0; i < R; i++) { A[i] = (char*)malloc(C + 1); A[i][C] = '\0'; }
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            A[i][j] = kill[i * C + j] ? '.' : 'O';
    free(kill);

    if (n % 4 == 3) {
        for (int i = 0; i < R; i++) memcpy(out[i], A[i], C);
        for (int i = 0; i < R; i++) free(A[i]);
        free(A);
        return out;
    }

    int* kill2 = (int*)calloc((size_t)R * C, sizeof(int));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (A[i][j] == 'O') {
                int idx = i * C + j;
                kill2[idx] = 1;
                for (int k = 0; k < 4; k++) {
                    int ni = i + di[k], nj = j + dj[k];
                    if ((unsigned)ni < (unsigned)R && (unsigned)nj < (unsigned)C) kill2[ni * C + nj] = 1;
                }
            }
        }
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            out[i][j] = kill2[i * C + j] ? '.' : 'O';

    free(kill2);
    for (int i = 0; i < R; i++) free(A[i]);
    free(A);

    return out;