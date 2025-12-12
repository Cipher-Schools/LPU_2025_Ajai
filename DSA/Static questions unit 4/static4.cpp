

int rec = 0;

void conquer(int arr[], int l, int m, int r, int size) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    rec++;
    cout << "\nAfter iteration " << rec << endl;
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
}

void divide(int arr[], int l, int r, int size) {
    if (l < r) {
        int m = l + (r - l) / 2;
        divide(arr, l, m, size);
        divide(arr, m + 1, r, size);
        conquer(arr, l, m, r, size);
    }
}
