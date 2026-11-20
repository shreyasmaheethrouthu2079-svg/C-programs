# DIY Solutions: Object-Oriented Programming in C++ (ECE121)

This directory contains complete, verified solutions for all 39 **Do-It-Yourself (DIY)** tasks from the ECE121 Object-Oriented Programming in C++ Lab Manual (NMAM Institute of Technology).

All programs follow modern C++17 standards, include comments explaining the underlying concepts and pitfalls, and compile cleanly with `-Wall`.

---

## Directory Structure

```text
diy/
├── week01/
│   ├── diy1_1_vowels_consonants.cpp     # Sentence vowel & consonant counter
│   ├── diy1_2_anagram.cpp               # Two-word anagram test using frequency array
│   └── diy1_3_reverse_words.cpp         # Reverse word order in a sentence
├── week02/
│   ├── diy2_1_overloaded_volume.cpp     # Overloaded volume for cube, cuboid, and cylinder
│   ├── diy2_2_default_arg_power.cpp     # Power calculator using default arguments
│   └── diy2_3_inline_min.cpp            # Overloaded inline minVal for 2 and 3 numbers
├── week03/
│   ├── diy3_1_rectangle.cpp             # Encapsulated Rectangle with validation & getters
│   ├── diy3_2_counter_array.cpp         # Counter class tested via an array of objects
│   └── diy3_3_complex_number.cpp        # Complex number class with setData and display
├── week04/
│   ├── diy4_1_dynamic_matrix.cpp        # Dynamic Matrix with deep copy ctor & dtor
│   ├── diy4_2_stack_destructor.cpp      # Dynamic integer Stack with destructor cleanup
│   └── diy4_3_lifetime_logger.cpp       # Lifetime Tracer: new/delete & memory leak demo
├── week05/
│   ├── diy5_1_object_counter.cpp        # Static members tracking created vs alive objects
│   ├── diy5_2_friend_comparison.cpp     # Friend function laterOf(Time, Time)
│   └── diy5_3_unique_id_factory.cpp     # Auto-incrementing order ID factory via static member
├── week06/
│   ├── diy6_1_money_arithmetic.cpp      # Money class with overloaded + and - (carry/borrow)
│   ├── diy6_2_fraction_io.cpp           # Fraction class with overloaded <<, >> and GCD reduction
│   └── diy6_3_safe_array.cpp            # Bounds-checked SafeArray overloading operator[]
├── week07/
│   ├── diy7_1_employee_hierarchy.cpp    # Employee base with Manager & Engineer derived classes
│   ├── diy7_2_multilevel_shapes.cpp     # Shape -> Polygon -> Rectangle constructor chain
│   └── diy7_3_resolve_diamond.cpp       # Diamond problem resolved using virtual base Person
├── week08/
│   ├── diy8_1_abstract_account.cpp      # Abstract Account interface with polymorphic interest
│   ├── diy8_2_polymorphic_logger.cpp    # Abstract Logger switched at runtime (Console/File)
│   └── diy8_3_virtual_destructor_leak.cpp # Proving & fixing memory leak with virtual destructor
├── week09/
│   ├── diy9_1_safe_withdrawal.cpp       # BankAccount throwing custom InsufficientFunds exception
│   ├── diy9_2_stack_exceptions.cpp      # Stack throwing custom StackOverflow and StackUnderflow
│   └── diy9_3_ordering_demo.cpp         # Catch-order demo: derived before base exceptions
├── week10/
│   ├── diy10_1_number_stats.cpp         # Read nums.txt: count, sum, min, max, average
│   ├── diy10_2_line_numbered_copy.cpp   # Read in.txt and write line-numbered out.txt
│   └── diy10_3_records_to_objects.cpp   # Parse student records from file into objects & find topper
├── week11/
│   ├── diy11_1_generic_utilities.cpp    # Template functions swapVals(T&,T&) and findMax()
│   ├── diy11_2_generic_queue.cpp        # Generic Queue<T> class template
│   └── diy11_3_frequency_counter.cpp    # Word frequency analysis with unordered_map<string,int>
├── week12/
│   ├── diy12_1_sort_pairs.cpp           # Sort vector<pair<string,int>> with lambda comparator
│   ├── diy12_2_top3_heap.cpp            # Find top-3 elements using priority_queue (heap)
│   └── diy12_3_custom_aggregate.cpp     # Custom accumulate: product of all & sum of evens
└── week13/
    ├── diy13_1_raw_to_smart.cpp         # Modern C++ RAII using unique_ptr and std::move
    ├── diy13_2_shape_factory_v2.cpp     # Shape Factory pattern storing unique_ptr<Shape> in vector
    └── diy13_3_prove_the_race.cpp       # Multithreading race condition vs mutex lock_guard
```

---

## How to Compile & Run

### Standard Build (Weeks 1 – 12)
```bash
g++ -std=c++17 -Wall path/to/program.cpp -o program
./program
```

### Multithreaded Build (Week 13)
```bash
g++ -std=c++17 -Wall -pthread path/to/program.cpp -o program
./program
```

### Memory Leak Verification (Week 4, Week 8)
```bash
g++ -std=c++17 -Wall -fsanitize=address path/to/program.cpp -o program
./program
```
