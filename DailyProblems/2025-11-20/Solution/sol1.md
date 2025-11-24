# **Problem: Check if Array is Sorted and Rotated**

You need to check if the array is:

* Already sorted → return true
* Sorted and then rotated at some pivot → return true
* Otherwise → false

---

# 🔥 **1. Brute Force Approach**

### **Idea**

Try **all possible rotations** of the array and check if any of them becomes sorted.

### **Steps**

1. For each index `i` from `0` to `n−1`:
   * Rotate array at index `i`.
   * Check if rotated version is sorted.
2. If any rotation gives sorted array → return true.
3. Else false.

### **Time Complexity**

* Checking sorted: **O(N)**
* Trying all rotations: **N times**
* **Total = O(N²)**

### **Space Complexity**

* Temporary rotated array → **O(N)**

### **Code (Brute)**

<pre class="overflow-visible!" data-start="901" data-end="1337"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>bool</span><span></span><span>isSorted</span><span>(vector<int</span><span>>& arr) {
    </span><span>for</span><span> (</span><span>int</span><span> i = </span><span>0</span><span>; i < arr.</span><span>size</span><span>() - </span><span>1</span><span>; i++) {
        </span><span>if</span><span> (arr[i] > arr[i+</span><span>1</span><span>]) </span><span>return</span><span></span><span>false</span><span>;
    }
    </span><span>return</span><span></span><span>true</span><span>;
}

</span><span>bool</span><span></span><span>checkBrute</span><span>(vector<int</span><span>>& nums) {
    </span><span>int</span><span> n = nums.</span><span>size</span><span>();

    </span><span>for</span><span> (</span><span>int</span><span> i = </span><span>0</span><span>; i < n; i++) {
        vector<</span><span>int</span><span>> temp;
        </span><span>for</span><span> (</span><span>int</span><span> j = </span><span>0</span><span>; j < n; j++)
            temp.</span><span>push_back</span><span>(nums[(i + j) % n]);

        </span><span>if</span><span> (</span><span>isSorted</span><span>(temp)) </span><span>return</span><span></span><span>true</span><span>;
    }
    </span><span>return</span><span></span><span>false</span><span>;
}
</span></span></code></div></div></pre>

---

# ⚡ **2. Better Approach**

### **Idea**

Find the **minimum element** and assume rotation happens there.

Reconstruct the array starting from the minimum element and check if sorted.

### **Steps**

1. Find index of minimum element `minIdx`.
2. Rebuild array starting at `minIdx`.
3. Check if the rebuilt array is sorted.

### **Time Complexity**

* Find minimum: **O(N)**
* Rebuild array: **O(N)**
* Check sorted: **O(N)**
* **Total = O(N)**

### **Space Complexity**

* Rebuilt array: **O(N)**

### **Code (Better)**

<pre class="overflow-visible!" data-start="1860" data-end="2230"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>bool</span><span></span><span>checkBetter</span><span>(vector<int</span><span>>& nums) {
    </span><span>int</span><span> n = nums.</span><span>size</span><span>();
    </span><span>int</span><span> minIdx = </span><span>min_element</span><span>(nums.</span><span>begin</span><span>(), nums.</span><span>end</span><span>()) - nums.</span><span>begin</span><span>();

    vector<</span><span>int</span><span>> temp;
    </span><span>for</span><span> (</span><span>int</span><span> i = </span><span>0</span><span>; i < n; i++)
        temp.</span><span>push_back</span><span>(nums[(minIdx + i) % n]);

    </span><span>for</span><span> (</span><span>int</span><span> i = </span><span>0</span><span>; i < n - </span><span>1</span><span>; i++) {
        </span><span>if</span><span> (temp[i] > temp[i+</span><span>1</span><span>])
            </span><span>return</span><span></span><span>false</span><span>;
    }
    </span><span>return</span><span></span><span>true</span><span>;
}
</span></span></code></div></div></pre>

---

# 🚀 **3. Optimal Approach (O(1) Space)** → Best for interviews

### **Idea**

Count number of places where `nums[i] > nums[i+1]`.

* If **count == 0** → already sorted
* If **count == 1** → sorted & rotated
* If **count > 1** → not valid

Also compare the **last element and first element** as part of the circular check.

### **Example**

`[3,4,5,1,2]`

Drop happens at `5 > 1` → count = 1 → ✔ rotated sorted

### **Time Complexity**

**O(N)**

### **Space Complexity**

**O(1)**

---

### **Code (Optimal)**

<pre class="overflow-visible!" data-start="2753" data-end="3017"><div class="contain-inline-size rounded-2xl relative bg-token-sidebar-surface-primary"><div class="sticky top-9"><div class="absolute end-0 bottom-0 flex h-9 items-center pe-2"><div class="bg-token-bg-elevated-secondary text-token-text-secondary flex items-center gap-4 rounded-sm px-2 font-sans text-xs"></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="whitespace-pre! language-cpp"><span><span>bool</span><span></span><span>checkOptimal</span><span>(vector<int</span><span>>& nums) {
    </span><span>int</span><span> n = nums.</span><span>size</span><span>();
    </span><span>int</span><span> count = </span><span>0</span><span>;

    </span><span>for</span><span> (</span><span>int</span><span> i = </span><span>0</span><span>; i < n; i++) {
        </span><span>if</span><span> (nums[i] > nums[(i + </span><span>1</span><span>) % n]) {
            count++;
        }
        </span><span>if</span><span> (count > </span><span>1</span><span>) </span><span>return</span><span></span><span>false</span><span>;
    }
    </span><span>return</span><span></span><span>true</span><span>;
}
</span></span></code></div></div></pre>

---

# 📌 Final Summary

| Approach          | Time Complexity | Space Complexity | Notes                     |
| ----------------- | --------------- | ---------------- | ------------------------- |
| **Brute**   | O(N²)          | O(N)             | Try all rotations         |
| **Better**  | O(N)            | O(N)             | Start from minimum        |
| **Optimal** | O(N)            | O(1)             | Count drops (best method) |
