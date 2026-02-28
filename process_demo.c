#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void) {
    pid_t pid;

    // 创建子进程
    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(1);
    } 
    else if (pid == 0) {
        // --- 子进程代码区 ---
        printf("[子进程] 我的 PID 是 %d，我即将退出...\n", getpid());
        exit(0); // 子进程立即退出，进入“僵尸”状态
    } 
    else {
        // --- 父进程代码区 ---
        printf("[父进程] 子进程 PID 是 %d\n", pid);
        printf("--- 阶段 1: 子进程已退出，但父进程还没执行 wait() ---\n");
        printf("请在另一个终端执行: ps aux | grep %d\n", pid);
        printf("你会看到状态为 'Z' (Zombie/Defunct)。然后在这里按 [Enter] 继续...\n");
        
        while (getchar() != '\n'); // 第一次暂停

        // 回收子进程
        printf("[父进程] 正在执行 wait(NULL) 回收子进程...\n");
        wait(NULL); 

        printf("--- 阶段 2: wait() 已执行 ---\n");
        printf("再次在另一个终端执行: ps aux | grep %d\n", pid);
        printf("你会发现子进程记录已经彻底消失。按 [Enter] 结束程序...\n");

        while (getchar() != '\n'); // 第二次暂停
    }

    return 0;
}