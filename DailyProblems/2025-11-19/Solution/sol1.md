# ## 1️⃣ Approach 1: Brute Force

### **Idea**

Check every pair using nested loops.

### **Code**

<pre class="overflow-visible!" data-start="921" data-end="1216"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>vector<int</span><span>> </span><span>twoSumBruteForce</span><span>(vector<int</span><span>>& nums, </span><span>int</span><span> target) {
    </span><span>int</span><span> n = nums.</span><span>size</span><span>();
    </span><span>for</span><span>(</span><span>int</span><span> i = </span><span>0</span><span>; i < n; i++) {
        </span><span>for</span><span>(</span><span>int</span><span> j = i + </span><span>1</span><span>; j < n; j++) {
            </span><span>if</span><span>(nums[i] + nums[j] == target) {
                </span><span>return</span><span> {i, j};
            }
        }
    }
    </span><span>return</span><span> {};
}
</span></span></code></div></div></pre>

### **Complexity**

| Metric          | Value  |
| --------------- | ------ |
| **Time**  | O(n²) |
| **Space** | O(1)   |

---

# ## 2️⃣ Approach 2: Hash Map (Optimal)

### **Idea**

Use a hash map to check if the **complement = target - nums[i]** already exists.

### **Code**

<pre class="overflow-visible!" data-start="1474" data-end="1826"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>vector<int</span><span>> </span><span>twoSumHashMap</span><span>(vector<int</span><span>>& nums, </span><span>int</span><span> target) {
    unordered_map<</span><span>int</span><span>, </span><span>int</span><span>> mp; </span><span>// value -> index</span><span>

    </span><span>for</span><span>(</span><span>int</span><span> i = </span><span>0</span><span>; i < nums.</span><span>size</span><span>(); i++) {
        </span><span>int</span><span> complement = target - nums[i];

        </span><span>if</span><span>(mp.</span><span>find</span><span>(complement) != mp.</span><span>end</span><span>()) {
            </span><span>return</span><span> {mp[complement], i};
        }

        mp[nums[i]] = i;
    }
    </span><span>return</span><span> {};
}
</span></span></code></div></div></pre>

### **Complexity**

| Metric          | Value |
| --------------- | ----- |
| **Time**  | O(n)  |
| **Space** | O(n)  |

---

# ## 3️⃣ Approach 3: Two Pointer (Sorted Array)

### **Idea**

1. Create an array of pairs `(value, index)`.
2. Sort by value.
3. Use **left** and **right** pointers to find the target sum.

### **Code**

<pre class="overflow-visible!" data-start="2143" data-end="2683"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>vector<int</span><span>> </span><span>twoSumTwoPointer</span><span>(vector<int</span><span>>& nums, </span><span>int</span><span> target) {
    </span><span>int</span><span> n = nums.</span><span>size</span><span>();

    vector<pair<</span><span>int</span><span>, </span><span>int</span><span>>> arr;
    </span><span>for</span><span>(</span><span>int</span><span> i = </span><span>0</span><span>; i < n; i++)
        arr.</span><span>push_back</span><span>({nums[i], i});

    </span><span>sort</span><span>(arr.</span><span>begin</span><span>(), arr.</span><span>end</span><span>());

    </span><span>int</span><span> left = </span><span>0</span><span>, right = n - </span><span>1</span><span>;

    </span><span>while</span><span>(left < right) {
        </span><span>int</span><span> sum = arr[left].first + arr[right].first;

        </span><span>if</span><span>(sum == target)
            </span><span>return</span><span> {arr[left].second, arr[right].second};
        </span><span>else</span><span></span><span>if</span><span>(sum < target)
            left++;
        </span><span>else</span><span>
            right--;
    }
    </span><span>return</span><span> {};
}
</span></span></code></div></div></pre>

### **Complexity**

| Metric          | Value      |
| --------------- | ---------- |
| **Time**  | O(n log n) |
| **Space** | O(n)       |

---

# 🎯 Final Recommendation

* Use **Hash Map Approach** (O(n)) → Best and most accepted solution.
* Two pointer is good for sorted problems.
* Brute force is only for basic explanation.
