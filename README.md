# aLogger

**aLogger** is a lightweight and flexible C++ logging utility designed to make terminal output cleaner and more structured. It supports multiple log types, color-coded formatting, command input handling, and saving log history as a JSON file.

---

## 🚀 Features

- ✅ Simple and expressive logging syntax
- 🎨 Colored terminal output with log type distinction
- 💾 Save log history as a structured JSON file
- 🧩 Support for custom commands with attached functionality
- 📋 Built-in log types: `regular`, `warning`, `error`, `internalConsoleError`, `table`, and `input`

---

## 🧱 Log Types

| Type                 | Description                     | Example Prefix         |
|----------------------|----------------------------------|------------------------|
| `regular`            | Default logs                    | `@ Hello world`        |
| `warning`            | Warnings                        | `@WARNING: Check this` |
| `error`              | Errors                          | `@ERROR: Something went wrong` |
| `internalConsoleError` | Internal logging failures      | `@INTERNAL CONSOLE ERROR:` |
| `table`              | For formatted or structured data | `TABLE: ...`          |
| `input`              | User command inputs             | `>/ command here`     |

## Example
![image](https://github.com/user-attachments/assets/ddd19321-65fb-426a-96b9-b35f96d604dd)


## 🔧 Installation

Add the library to your project:

### 1. Clone the repo (or add as a submodule)
```bash
git clone https://github.com/YourUsername/aLogger.git
