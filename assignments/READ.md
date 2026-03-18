# Assignment: Register Frame Generator

## 📌 Overview

This program simulates a simple **register communication system** in C.
It generates formatted binary frames for **read** and **write** operations on registers.

The program uses:

* Enums for register names
* Structures with bit-fields
* Binary conversion logic
* Frame formatting

---

## 🧠 Concepts Used

* Structures and Enums in C
* Bit-fields
* String manipulation
* Binary conversion
* Function design

---

## ⚙️ Program Description

The program defines a register structure containing:

* `reg_name` → Register identifier (GPIO0 to GPIO4)
* `reg_adrs` → 10-bit register address
* `reg_data` → 16-bit register data

A fixed CRC value `"101"` is used in frame generation.

An array of registers is initialized, and operations are performed on one of the registers.

---

## 🔄 How It Works

### 1. Register Definition

Registers are defined using enum and struct with bit-fields:

* Address → 10 bits
* Data → 16 bits

---

### 2. Binary Conversion

Functions are used to convert integers into binary strings:

* Register address → binary
* Register data → binary
* Input value → binary

---

### 3. Read Operation

The `read()` function:

* Converts address and data to binary
* Pads them to fixed sizes (10-bit and 16-bit)
* Generates a frame:

```
0|0|address|data|crc|0
```

---

### 4. Write Operation

The `write()` function:

* Converts address and new data to binary
* Pads them to fixed sizes
* Generates a frame:

```
1|0|address|data|crc|0
```

---

## ▶️ Execution

In `main()`:

* An array of registers is created
* A register is selected
* Read and write frames are generated
* Output is printed

---

## 🧾 Example Output

```
0|0|0000000100|0000000000110010|101|0
1|0|0000000100|0000000000101101|101|0
```

---

## ⚠️ Note

This implementation focuses on functionality and clarity.
It is not fully optimized and contains repeated logic for binary conversion, which can be improved in future versions.

---

## 🚀 Conclusion

This program demonstrates how register values can be converted into structured binary frames, similar to communication protocols used in embedded systems.
