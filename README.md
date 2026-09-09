# Lab 1 - Installing VS Code and GCC — Writing Your First C Program

For this course, we will use:

* **Visual Studio Code (VS Code)** — VS Code is a lightweight code editor that can be configured for C/C++ programming. It works well on both Windows and macOS.
* **GCC (`gcc`)** — GCC (GNU Compiler Collection) is a foundational software tool that translates programming source code into binary machine code that computer hardware can execute.

---

## 1. Install Visual Studio Code

Download and install **Visual Studio Code (VS Code)** from [https://code.visualstudio.com](https://code.visualstudio.com/download?_exp_download=fb315fc982){:target="_blank"}.

Then install the **C/C++ Extension Pack by Microsoft** from the Extensions panel in VS Code.

---

## 2. Install a C Compiler

### GCC and Clang

**GCC (GNU Compiler Collection)** and **Clang** are two widely used compilers for C and C++.

For this course, we will use the **`gcc` command** when demonstrating how to compile C programs.

#### Windows: Install MinGW-w64

Windows does not come with a C compiler, so you'll need to install one:

1. Download and install **MSYS2** from [msys2.org](https://www.msys2.org){:target="_blank"}.
2. Open the **MSYS2 UCRT64** terminal (not the regular MSYS2 terminal) from the Start menu.
3. Run the following command to install the GCC toolchain:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc
   ```
4. **Add GCC to your PATH.** This is the step most students get stuck on. You need to add the following folder to your Windows PATH environment variable:
   ```text
   C:\msys64\ucrt64\bin
   ```
   To do this: search for "Environment Variables" in the Windows Start menu → **Edit the system environment variables** → **Environment Variables** → under "User variables," select **Path** → **Edit** → **New** → paste the folder path above → OK on all windows.
5. **Close and reopen** any open terminal or VS Code window so the PATH change takes effect.

> If `gcc --version` still doesn't work after this, double-check the PATH entry is spelled exactly right and that you restarted the terminal (not just opened a new tab).

#### macOS: Install Xcode Command Line Tools

macOS does not have a compiler installed by default, even though `gcc` and `clang` are referenced by the system. Before anything will work, you must install Apple's Command Line Tools:

1. Open **Terminal**.
2. Run:
   ```bash
   xcode-select --install
   ```
3. A popup will appear — click **Install** and agree to the license. This may take several minutes.

Once installed, the `gcc` command will work — but it actually invokes **Apple's Clang compiler**, not the real GNU GCC. **This is normal and is fine for this course.**

### Check that your compiler is installed

Open the VS Code Terminal and enter:

```bash
gcc --version
```

If the compiler is installed correctly, you should see version information.

> **Note for macOS:** If the output says `Apple clang`, don't worry — that's expected. The `gcc` command on macOS refers to Apple's Clang compiler.

> **Note for Windows:** If you see `'gcc' is not recognized as an internal or external command`, your PATH is not set up correctly. Revisit the PATH step above and restart your terminal.

---

## 3. Create Your First C Program

Open VS Code and create a new file called:

```text
hello.c
```

Enter the following program:

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, world!\n");
    return 0;
}
```

Save the file.

The `.c` extension tells the compiler that this is a **C source file**.

---

## 4. Compile Your Program

Open the VS Code Terminal and make sure you are in the folder containing `hello.c`.

Run:

```bash
gcc hello.c -o hello
```

Here:

* `gcc` — the C compiler command
* `hello.c` — your source file
* `-o hello` — tells the compiler to name the output program `hello`

If there are no errors, your program has been compiled successfully.

### Recommended: Compile with warnings enabled

Starting now, it's good practice to compile with extra warnings turned on. These don't stop your program from compiling, but they catch common mistakes (like unused variables or type mismatches) before they turn into bugs:

```bash
gcc -Wall -Wextra hello.c -o hello
```

* `-Wall` — enables most common warnings
* `-Wextra` — enables additional warnings not covered by `-Wall`

We recommend using `-Wall -Wextra` for every program you compile in this course, and treating warnings as things to fix, not ignore.

---

## 5. Run Your Program

### Windows

```bash
.\hello.exe
```

### macOS

```bash
./hello
```

You should see:

```text
Hello, world!
```

🎉 **Congratulations! You have compiled and run your first C program.**

---

## 6. Basic Workflow

For most programs in this course, you will follow this cycle:

**Write → Save → Compile → Run → Test → Debug → Repeat**

For example:

```bash
gcc -Wall -Wextra program.c -o program
```

Then run the program:

**Windows**

```bash
.\program.exe
```

**macOS**

```bash
./program
```

---

## 7. Troubleshooting

| Problem | Likely Cause | Fix |
| --- | --- | --- |
| `'gcc' is not recognized...` (Windows) | GCC not on PATH | Revisit Step 2 PATH setup; restart terminal |
| `command not found: gcc` (macOS) | Xcode Command Line Tools not installed | Run `xcode-select --install` |
| VS Code shows red squiggles under `#include <stdio.h>` but code still compiles | VS Code's IntelliSense can't find the compiler | Usually cosmetic — safe to ignore if `gcc` compiles fine in the terminal. Can be fixed by configuring `c_cpp_properties.json` (ask your instructor if this bothers you) |
| `./hello` says "Permission denied" (macOS) | Rare filesystem permission issue | Run `chmod +x hello` then try again |
| Changes to code don't seem to appear when you run the program | Forgot to save the file, or forgot to re-compile | Save the file, then re-run the `gcc` compile command before running again |
| Terminal opens to the wrong folder | Working directory doesn't contain your `.c` file | Use `cd` to navigate to the correct folder, or open VS Code directly in your project folder |

If none of these fix your issue, bring your laptop to office hours — environment setup issues are almost always quick to resolve in person.

---

## 8. Other C Development Environments

You may encounter other tools for C programming:

* **Xcode** — Apple's development environment for macOS
* **CLion** — a full-featured C/C++ IDE that works on Windows and macOS
* **Clang** — another major C/C++ compiler

You are welcome to use another IDE or compiler if you already have experience with it. However, **VS Code + `gcc` will be the setup used for demonstrations and examples in this course.**

### Quick Reference

| Component                      | Windows         | macOS           |
| ------------------------------ | --------------- | --------------- |
| Editor                         | VS Code         | VS Code         |
| C/C++ extension                | Microsoft C/C++ | Microsoft C/C++ |
| Compiler toolchain to install  | MinGW-w64 (via MSYS2) | Xcode Command Line Tools |
| Compiler command used in class | `gcc`           | `gcc`           |
| Typical compiler behind `gcc`  | GCC             | Apple Clang     |
| Source file                    | `.c`            | `.c`            |

### Essential Commands

Check compiler:

```bash
gcc --version
```

Compile (with warnings enabled — recommended):

```bash
gcc -Wall -Wextra program.c -o program
```

Run on Windows:

```bash
.\program.exe
```

Run on macOS:

```bash
./program
```

**For this course, don't worry about the differences between GCC and Clang. Focus on learning C and understanding the compile–run process.**
