# Installing VS Code and GCC — Writing Your First C Program

For this course, we will use:

* **Visual Studio Code (VS Code)** — VS Code is a lightweight code editor that can be configured for C/C++ programming. It works well on both Windows and macOS.
* **GCC (`gcc`)** — GCC (GNU Compiler Collection) is a foundational software tool that translates programming source code into binary machine code that computer hardware can execute. **GCC** and **Clang** are two widely used compilers for C and C++. For this course, we will use the **`gcc` command** when demonstrating how to compile C programs.


---

## 1. Install Visual Studio Code

Download and install **Visual Studio Code (VS Code)** from [https://code.visualstudio.com](https://code.visualstudio.com/download?_exp_download=fb315fc982).

Then install the **C/C++ Extension Pack by Microsoft** from the Extensions panel in VS Code.

---

## 2. Install a C Compiler

### Before install, firstly check if your compiler is installed already.

Open the VS Code Terminal and enter:

```bash
gcc --version
```

If the compiler is installed correctly, you should see version information, and you can jump to Step 3 now.
Otherwise, continue the following:


#### Windows: Install MinGW-w64

Windows does not come with a C compiler, so you'll need to install one:

1. Download and install **MSYS2** from [msys2.org](https://www.msys2.org). Follow the page until step 8 to install GCC.
2. **Add GCC to your PATH.** In your **VS Code terminal**, run:
   ```bash
   [Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\msys64\ucrt64\bin", "User")
   ```
3. **Close and reopen** any open terminal or VS Code window so the PATH change takes effect.

#### macOS: Install Xcode Command Line Tools

macOS does not have a compiler installed by default, even though `gcc` and `clang` are referenced by the system. Before anything will work, you must install Apple's Command Line Tools:

1. Open the VS Code **Terminal**.
2. Run:
   ```bash
   xcode-select --install
   ```
3. A popup will appear — click **Install** and agree to the license. This may take several minutes.

Once installed, the `gcc` command will work — but it actually invokes **Apple's Clang compiler**, not the real GNU GCC. **This is normal and is fine for this course.**

## 3. Create Your First C Program

Open the VS Code Terminal, and run the following command to open a new file named `hello.c`:
```bash
code hello.c
```

> **Note (macOS only):** If you see
> ```bash
> command not found: code
> ```
> that's because `code` isn't added to your shell's PATH by default. You need to manually enable it once:
> 1. Open VS Code
> 2. Press `Cmd+Shift+P` to open the Command Palette
> 3. Type and select **"Shell Command: Install 'code' command in PATH"**
> 4. Restart your terminal and run `code hello.c` again.

Enter the following program:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

Save the file.

The `.c` extension tells the compiler that this is a **C source file**.

---

## 4. Compile Your Program

In the VS Code Terminal, Run:

```bash
gcc hello.c -o hello
```

Here:

* `gcc` — the C compiler command
* `hello.c` — your source file
* `-o hello` — tells the compiler to name the output program `hello`

If there are no errors, your program has been compiled successfully.

---

## 5. Run Your Program

```bash
./hello
```

You should see:

```text
Hello, world!
```
Otherwise, follow the workflow of **Write → Save → Compile → Run → Test → Debug → Repeat** to fix it.

🎉 **Congratulations! You have compiled and run your first C program. Now complete your [lab1 quiz](https://elearn.capu.ca/mod/quiz/attempt.php?attempt=2249358&cmid=3395889) on e-Learn. And that's all for lab1.**

