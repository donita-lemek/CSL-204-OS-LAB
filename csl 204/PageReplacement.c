#include <stdio.h>
#define MAX_FRAMES 3

void fifo(int pages[], int n) {
int frames[MAX_FRAMES], front = 0, pageFaults = 0;
for (int i = 0; i < MAX_FRAMES; i++) frames[i] = -1;
printf("\nFIFO Page Replacement\nPage Reference String | Frame Status\n-empty-\n");
for (int i = 0; i < n; i++) {
int found = 0;
for (int j = 0; j < MAX_FRAMES; j++) if (frames[j] == pages[i]) { found = 1; break; }
if (!found) { frames[front] = pages[i]; front = (front + 1) % MAX_FRAMES; pageFaults++; }
printf("%10d          |", pages[i]);
for (int j = 0; j < MAX_FRAMES; j++) if (frames[j] == -1) printf("  -"); else printf(" %2d", frames[j]);
printf("\n");
}
printf("\nTotal Page Faults: %d\n", pageFaults);
}

void lru(int pages[], int n) {
int frames[MAX_FRAMES], recent[MAX_FRAMES], pageFaults = 0;
for (int i = 0; i < MAX_FRAMES; i++) { frames[i] = -1; recent[i] = -1; }
printf("\nLRU Page Replacement\nPage Reference String | Frame Status\n-empty-\n");
for (int i = 0; i < n; i++) {
int found = 0, index = -1;
for (int j = 0; j < MAX_FRAMES; j++) if (frames[j] == pages[i]) { found = 1; recent[j] = i; break; }
if (!found) {
if (i < MAX_FRAMES) index = i;
else {
int lru_index = 0;
for (int j = 1; j < MAX_FRAMES; j++) if (recent[j] < recent[lru_index]) lru_index = j;
index = lru_index;
}
frames[index] = pages[i]; recent[index] = i; pageFaults++;
}
printf("%10d          |", pages[i]);
for (int j = 0; j < MAX_FRAMES; j++) if (frames[j] == -1) printf("  -"); else printf(" %2d", frames[j]);
printf("\n");
}
printf("\nTotal Page Faults: %d\n", pageFaults);
}

void optimal(int pages[], int n) {
int frames[MAX_FRAMES], pageFaults = 0;
for (int i = 0; i < MAX_FRAMES; i++) frames[i] = -1;
printf("\nOptimal Page Replacement\nPage Reference String | Frame Status\n-empty-\n");
for (int i = 0; i < n; i++) {
int found = 0;
for (int j = 0; j < MAX_FRAMES; j++) if (frames[j] == pages[i]) { found = 1; break; }
if (!found) {
if (i < MAX_FRAMES) frames[i] = pages[i];
else {
int farthest = -1, replace_index = -1;
for (int j = 0; j < MAX_FRAMES; j++) {
int next_use = n;
for (int k = i + 1; k < n; k++) if (frames[j] == pages[k]) { next_use = k; break; }
if (next_use > farthest) { farthest = next_use; replace_index = j; }
}
frames[replace_index] = pages[i];
}
pageFaults++;
}
printf("%10d          |", pages[i]);
for (int j = 0; j < MAX_FRAMES; j++) if (frames[j] == -1) printf("  -"); else printf(" %2d", frames[j]);
printf("\n");
}
printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
int n;
printf("Enter number of pages: ");
scanf("%d", &n);
int pages[n];
printf("Enter the page reference string: ");
for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
fifo(pages, n);
lru(pages, n);
optimal(pages, n);
return 0;
}

