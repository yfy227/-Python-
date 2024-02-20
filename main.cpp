#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 256

int main() {
    // 初始化Python解释器
    Py_Initialize();

    // 打开包含Python脚本文件路径的文本文件
    FILE* file = fopen("/storage/emulated/0/专存路径/1.txt", "r");
    if (!file) {
        printf("Failed to open file.\n");
        return 1;
    }

    // 逐行读取文本文件中的绝对路径并执行Python脚本文件
    char path[MAX_PATH_LENGTH];
    while (fgets(path, MAX_PATH_LENGTH, file) != NULL) {
        // 去除换行符
        strtok(path, "\n");

        // 导入脚本模块
        PyObject* pModule = PyImport_ImportModule("__main__");

        if (pModule) {
            // 打开指定路径的Python脚本文件
            FILE* pyFile = fopen(path, "r");

            if (pyFile) {
                // 执行Python脚本文件
                PyRun_SimpleFile(pyFile, path);

                // 关闭Python脚本文件
                fclose(pyFile);
            } else {
                printf("Failed to open Python script file: %s\n", path);
            }

            // 释放模块对象
            Py_DECREF(pModule);
        } else {
            PyErr_Print();
        }
    }

    // 关闭文本文件
    fclose(file);

    // 关闭Python解释器
    Py_Finalize();

    return 0;
}
