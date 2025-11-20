# --------------------------------------------------------------

# 1️⃣ **Brute Force Approach (O(N²))**

# --------------------------------------------------------------

### **Idea**

Check every pair using nested loops.

---

### **C++ Code**

<pre class="overflow-visible!" data-start="977" data-end="1237"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>bool</span><span></span><span>pairBruteForce</span><span>(vector<int</span><span>>& arr, </span><span>int</span><span> X) {
    </span><span>int</span><span> n = arr.</span><span>size</span><span>();
    </span><span>for</span><span> (</span><span>int</span><span> i = </span><span>0</span><span>; i < n; i++) {
        </span><span>for</span><span> (</span><span>int</span><span> j = i + </span><span>1</span><span>; j < n; j++) {
            </span><span>if</span><span> (arr[i] + arr[j] == X)
                </span><span>return</span><span></span><span>true</span><span>;
        }
    }
    </span><span>return</span><span></span><span>false</span><span>;
}
</span></span></code></div></div></pre>

---

### **Complexity**

* **Time:** O(N²)
* **Space:** O(1)

---

# --------------------------------------------------------------

# 2️⃣ **Better Approach – Hashing (O(N))**

# --------------------------------------------------------------

### **Idea**

Use a hash set to check if `X - arr[i]` exists.

---

### **C++ Code**

<pre class="overflow-visible!" data-start="1565" data-end="1831"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>bool</span><span></span><span>pairUsingHashing</span><span>(vector<int</span><span>>& arr, </span><span>int</span><span> X) {
    unordered_set<</span><span>int</span><span>> s;

    </span><span>for</span><span> (</span><span>int</span><span> num : arr) {
        </span><span>int</span><span> complement = X - num;

        </span><span>if</span><span> (s.</span><span>find</span><span>(complement) != s.</span><span>end</span><span>())
            </span><span>return</span><span></span><span>true</span><span>;

        s.</span><span>insert</span><span>(num);
    }

    </span><span>return</span><span></span><span>false</span><span>;
}
</span></span></code></div></div></pre>

---

### **Complexity**

| Metric          | Value |
| --------------- | ----- |
| **Time**  | O(N)  |
| **Space** | O(N)  |

---

# --------------------------------------------------------------

# 3️⃣ **Optimal Approach – Two Pointers (O(N), O(1))**

# --------------------------------------------------------------

### **Idea**

Since the array is  **sorted** , use two indexes:

* `low` → start
* `high` → end

Move pointers based on the current sum.

---

### **C++ Code**

<pre class="overflow-visible!" data-start="2285" data-end="2601"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>bool</span><span></span><span>pairTwoPointer</span><span>(vector<int</span><span>>& arr, </span><span>int</span><span> X) {
    </span><span>int</span><span> low = </span><span>0</span><span>, high = arr.</span><span>size</span><span>() - </span><span>1</span><span>;

    </span><span>while</span><span> (low < high) {
        </span><span>int</span><span> sum = arr[low] + arr[high];

        </span><span>if</span><span> (sum == X)
            </span><span>return</span><span></span><span>true</span><span>;
        </span><span>else</span><span></span><span>if</span><span> (sum < X)
            low++;
        </span><span>else</span><span>
            high--;
    }

    </span><span>return</span><span></span><span>false</span><span>;
}
</span></span></code></div></div></pre>

---

### **Complexity**

| Metric          | Value |
| --------------- | ----- |
| **Time**  | O(N)  |
| **Space** | O(1)  |

---

# 🎯 Final Recommendation

| Approach                        | When to Use                 |
| ------------------------------- | --------------------------- |
| **Brute Force**           | For explanation / beginners |
| **Hashing (Better)**      | Array is unsorted           |
| **Two Pointer (Optimal)** | Array is**sorted**    |
