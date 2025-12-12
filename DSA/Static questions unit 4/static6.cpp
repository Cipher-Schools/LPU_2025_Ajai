int moveDisks(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "move disk 1 from rod " << source << " to rod " << destination << endl;
        return 1;
    } else {
        // Move n-1 disks from source to auxiliary using destination
        int moves1 = moveDisks(n - 1, source, destination, auxiliary);
        // Move the nth disk from source to destination
        cout << "move disk " << n << " from rod " << source << " to rod " << destination << endl;
        // Move n-1 disks from auxiliary to destination using source
        int moves2 = moveDisks(n - 1, auxiliary, source, destination);
        return moves1 + moves2 + 1;
    }
}