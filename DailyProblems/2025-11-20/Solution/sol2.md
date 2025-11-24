# **Problem: Count Pairs With Given Difference**

![1763963968685](image/sol2/1763963968685.png)

# ✅ **1. Brute Force Approach**

### **Idea**

Check all pairs `(i, j)` using two nested loops.

### **Steps**

* Loop `i` from `0 to n-1`
* Loop `j` from `0 to n-1`
* If `arr[i] - arr[j] == k`, increment count

### **Time Complexity**

**O(N²)** → double loop

### **Space Complexity**

**O(1)**

### **Code (Brute)**

<pre class="overflow-visible!" data-start="654" data-end="921"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>int</span><span></span><span>countBrute</span><span>(vector<int</span><span>> &arr, </span><span>int</span><span> k) {
    </span><span>int</span><span> n = arr.</span><span>size</span><span>();
    </span><span>int</span><span> count = </span><span>0</span><span>;

    </span><span>for</span><span> (</span><span>int</span><span> i = </span><span>0</span><span>; i < n; i++) {
        </span><span>for</span><span> (</span><span>int</span><span> j = </span><span>0</span><span>; j < n; j++) {
            </span><span>if</span><span> (arr[i] - arr[j] == k)
                count++;
        }
    }
    </span><span>return</span><span> count;
}
</span></span></code></div></div></pre>

---

# ⚡ **2. Better Approach – Sorting + Two Pointers**

### **Idea**

Sort the array and use two pointers `i` and `j`.

### **Steps**

1. Sort array
2. Use two pointers:
   * If `arr[j] - arr[i] < k` → move `j++`
   * If `arr[j] - arr[i] > k` → move `i++`
   * If equal → count++, move both

### **Time Complexity**

* Sorting: **O(N log N)**
* Two pointers: **O(N)**

  ✔ Total: **O(N log N)**

### **Space Complexity**

**O(1)** (if sorting in-place)

### **Code (Better)**

<pre class="overflow-visible!" data-start="1395" data-end="1839"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>int</span><span></span><span>countBetter</span><span>(vector<int</span><span>> &arr, </span><span>int</span><span> k) {
    </span><span>sort</span><span>(arr.</span><span>begin</span><span>(), arr.</span><span>end</span><span>());
    </span><span>int</span><span> n = arr.</span><span>size</span><span>();
    </span><span>int</span><span> i = </span><span>0</span><span>, j = </span><span>1</span><span>, count = </span><span>0</span><span>;

    </span><span>while</span><span> (j < n) {
        </span><span>int</span><span> diff = arr[j] - arr[i];

        </span><span>if</span><span> (diff == k) {
            count++;
            i++;
            j++;
        } 
        </span><span>else</span><span></span><span>if</span><span> (diff < k) {
            j++;
        } 
        </span><span>else</span><span> {
            i++;
        }

        </span><span>if</span><span> (i == j) j++;
    }
    </span><span>return</span><span> count;
}
</span></span></code></div></div></pre>

---

# 🚀 **3. Optimal Approach – Using Hashing (O(N))**

### **Idea**

For every element `x` in array:

* Check if `(x + k)` exists
* Because:

  arr[i]−arr[j]=k  ⟺  arr[i]=arr[j]+karr[i] - arr[j] = k \iff arr[i] = arr[j] + k**a**rr**[**i**]**−**a**rr**[**j**]**=**k**⟺**a**rr**[**i**]**=**a**rr**[**j**]**+**k**

### **Steps**

1. Insert all elements into an unordered set.
2. For each `x`, check if `x + k` exists.
3. Count such matches.

### **Time Complexity**

**O(N)** — hash lookups are O(1)

### **Space Complexity**

**O(N)** — for the hash set

### **Code (Optimal)**

<pre class="overflow-visible!" data-start="2307" data-end="2544"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>int</span><span></span><span>countOptimal</span><span>(vector<int</span><span>> &arr, </span><span>int</span><span> k) {
    </span><span>unordered_set<int</span><span>> </span><span>st</span><span>(arr.begin(), arr.end())</span><span>;
    </span><span>int</span><span> count = </span><span>0</span><span>;

    </span><span>for</span><span> (</span><span>int</span><span> x : arr) {
        </span><span>if</span><span> (st.</span><span>count</span><span>(x + k)) {
            count++;
        }
    }
    </span><span>return</span><span> count;
}
</span></span></code></div></div></pre>

---

# 📌 Final Summary Table

| Approach                                | Time Complexity | Space Complexity | Notes                       |
| --------------------------------------- | --------------- | ---------------- | --------------------------- |
| **Brute**                         | O(N²)          | O(1)             | Check all pairs             |
| **Better (Sorting + 2 Pointers)** | O(N log N)      | O(1)             | Efficient but needs sorting |
| **Optimal (Hashing)**             | **O(N)**  | **O(N)**   | Best solution               |

---
