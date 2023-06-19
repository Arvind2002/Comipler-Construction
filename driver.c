#include "symbolTable.c"

/*
GROUP_NO_34
Aditya Kanthi - 2020A7PS0087P
Shirish Kumaravel - 2020A7PS0131P
Arvind Ram - 2020A7PS1210P
Aryan Kapoor - 2020A7PS1689P 
*/

int main(int argc, char *argv[]){
    if(argc<3){
        printf("\n\tINPUT ALL COMMAND LINE ARGUMENTS\n\t1.Input testcase file\n\t2.Output file for the assembly language code\n");
        exit(0);
    }
    char* inputTestCaseFile = argv[1];
    char* outputParseTreeFile = "outputParseTree.txt";
    char* outputAssemblyFile = argv[2];
    long long int bufSize = 10000;
    printf("%lld\n",bufSize);
    clock_t start_time, end_time;
    double total_CPU_time, total_CPU_time_in_seconds;
    printf("LEVEL 4: AST WORKS/ SYMBOL TABLE WORKS/ TYPE-CHECKING AND SEMANTIC RULES MODULES WORK\n\n");
    printf("<----------COMPILER PROJECT STAGE 2---------->\n");
    printf("\tGROUP_34:\n");
    printf("\tADITYA KANTHI\t\t2020A7PS0087P\n");
    printf("\tSHIRISH KUMARAVEL\t2020A7PS0131P\n");
    printf("\tARVIND RAM\t\t2020A7PS1210P\n");
    printf("\tARYAN KAPOOR\t\t2020A7PS1689P\n");

    //lexer initialisations
    printf("MENU:\n");
    printf("\t0:\tExit\n");
    printf("\t1:\tPrint the token list generated by the lexer\n");
    printf("\t2:\tParse the input source code to verify syntactic correctness and print the parse tree\n");
    printf("\t3:\tPrint AST\n");
    printf("\t4:\tPrint memory information and compression percentage\n");
    printf("\t5:\tPrint Symbol Table\n");
    printf("\t6:\tPrint the total memory requirement for each function\n");
    printf("\t7:\tPrint type expressions and width of array variables\n");
    printf("\t8:\tVerify the syntactic and semantic correctness of the input source code\n");
    printf("\t9:\tProduce assembly code\n");
    printf("\n\tINPUT YOUR CHOICE: ");
    int choice,filechoice;
    char filename[30];
    scanf("%d",&choice);
    while(choice<0 || choice>9){
        printf("\t***Please choose a number between 0 and 9***\n");
        printf("\tINPUT YOUR CHOICE: ");
        scanf("%d",&choice);
    }
    switch(choice){
        case 0:
            printf("\tThank you for your time!\n");
            exit(0);
            break;
        case 1:
            printf("\tSTARTING LEXICAL ANALYSIS ON %s:\n",inputTestCaseFile);
            initialiseLexer(inputTestCaseFile,bufSize);
            printf("\tLINE_NO\t\t\tLEXEME\t\t\tTOKEN_NAME\n");
            printf("\t----------------------------------------------------------\n");
            token curToken;
            int count = 0;
            while(!finishedReading){
                curToken = getNextToken(fp);
                if(curToken.lexeme == NULL) {
                    continue;
                }
                count++;
                printf("\t%d\t\t\t%s\t\t\t%s\n",curToken.lineNum,curToken.lexeme,grammarArr[curToken.gItem]);
            }
            exit(0);
            break;

        case 2:
            printf("\tPARSING %s:\n",inputTestCaseFile);
            initialiselexer(inputTestCaseFile,bufSize);
            token currToken;
            int cnt = 0;
            while(!finishedReading){
                currToken = getNextToken(fp);
                if((currToken.gItem == 0) || (currToken.gItem == COMMENT)) {
                    continue;
                }
                cnt++;
            }
            cnt++;
            initialiselexer(inputTestCaseFile,bufSize);
            token* toks  = (token*)malloc(sizeof(token)*cnt);
            int i = 0;
            while(!finishedReading){
                currToken = getNextToken(fp);
                if((currToken.gItem == 0) || (currToken.gItem == COMMENT)) {
                    continue;
                }
                toks[i] = currToken;
                i++;
            }
            token nextToken;
            nextToken.lexeme = NULL;
            nextToken.lineNum = 0;
            nextToken.gItem = DUMMY;
            nextToken.intVal = 0;
            nextToken.floatVal = 0.0;
            toks[cnt-1] = nextToken;
            initializeParser(toks,cnt);
            initialiseParseHelpers();
            treeNodePtr parseTree = createParseTree(inputTestCaseFile);
            printParseTree(parseTree, outputParseTreeFile);
            exit(0);
            break;

        case 3:
            initialiselexer(inputTestCaseFile,bufSize);
            token currToke;
            int cnt1 = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                cnt1++;
            }
            cnt1++;
            initialiselexer(inputTestCaseFile,bufSize);
            token* toks1  = (token*)malloc(sizeof(token)*cnt1);
            int k = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                toks1[k] = currToke;
                k++;
            }
            token nextToke;
            nextToke.lexeme = NULL;
            nextToke.lineNum = 0;
            nextToke.gItem = DUMMY;
            nextToke.intVal = 0;
            nextToke.floatVal = 0.0;
            toks1[cnt1-1] = nextToke;
            initializeParser(toks1,cnt1);
            initialiseParseHelpers();
            treeNodePtr tree = createParseTree(inputTestCaseFile);
            //printf("Printing Parse Tree\n\n");
           // printParser(tree);
            //printParseTree(tree, outputParseTreeFile);
            printf("--------------------------------------PRINTING AST THROUGH INORDER TRAVERSAL----------------------------------\n");
            astNode* ast = makeAST(-1,-1,tree, NULL,NULL);
            printAST(ast);
            exit(0);
            break;
        case 4:
        {
            initialiselexer(inputTestCaseFile,bufSize);
            token currToke;
            int cnt1 = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                cnt1++;
            }
            cnt1++;
            initialiselexer(inputTestCaseFile,bufSize);
            token* toks1  = (token*)malloc(sizeof(token)*cnt1);
            int k = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                toks1[k] = currToke;
                k++;
            }
            token nextToke;
            nextToke.lexeme = NULL;
            nextToke.lineNum = 0;
            nextToke.gItem = DUMMY;
            nextToke.intVal = 0;
            nextToke.floatVal = 0.0;
            toks1[cnt1-1] = nextToke;
            initializeParser(toks1,cnt1);
            initialiseParseHelpers();
            treeNodePtr tree = createParseTree(inputTestCaseFile);
            int parseTreeSize = getParseTreeSize(tree);
            printf("Parse Tree Size: %d\n",parseTreeSize);
            //printf("Printing Parse Tree\n\n");
            //printParser(tree);
            //printParseTree(tree, outputParseTreeFile);
            //printf("\n\n\n\nPrinting AST\n\n");
            astNode* ast = makeAST(-1,-1,tree, NULL,NULL);
            int astSize = getASTSize(ast);
            printf("AST Size: %d\n",astSize);
            //printAST(ast);
            double comp = (double)(parseTreeSize-astSize)/(double)parseTreeSize;
            comp=comp*100;
            printf("Compression Percentage: %lf\n",comp);
            exit(0);
        }
            break;
        case 5: 
        {
         start_time = clock();   
        initialiselexer(inputTestCaseFile,bufSize);
            token currToke;
            int cnt1 = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                cnt1++;
            }
            cnt1++;
            initialiselexer(inputTestCaseFile,bufSize);
            token* toks1  = (token*)malloc(sizeof(token)*cnt1);
            int k = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                toks1[k] = currToke;
                k++;
            }
            token nextToke;
            nextToke.lexeme = NULL;
            nextToke.lineNum = 0;
            nextToke.gItem = DUMMY;
            nextToke.intVal = 0;
            nextToke.floatVal = 0.0;
            toks1[cnt1-1] = nextToke;
            initializeParser(toks1,cnt1);
            initialiseParseHelpers();
            treeNodePtr tree = createParseTree(inputTestCaseFile);
            //printf("Printing Parse Tree\n\n");
           // printParser(tree);
            //printParseTree(tree, outputParseTreeFile);
            printf("--------------------------------------PRINTING SYMBOL TABLE----------------------------------\n");
            astNode* ast = makeAST(-1,-1,tree, NULL,NULL);
            populateSymbolTable(ast);
            end_time = clock();
            printSymbolTable();
            total_CPU_time = (double) (end_time - start_time);
            total_CPU_time_in_seconds = total_CPU_time /CLOCKS_PER_SEC;
            printf("\tTIME TAKEN FOR %s:\n",inputTestCaseFile);
            printf("\t In ticks:%f\n",total_CPU_time);
            printf("\t In seconds:%f\n",total_CPU_time_in_seconds);
            exit(0);
            break;
        }
        case 6:{
            initialiselexer(inputTestCaseFile,bufSize);
            token currToke;
            int cnt1 = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                cnt1++;
            }
            cnt1++;
            initialiselexer(inputTestCaseFile,bufSize);
            token* toks1  = (token*)malloc(sizeof(token)*cnt1);
            int k = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                toks1[k] = currToke;
                k++;
            }
            token nextToke;
            nextToke.lexeme = NULL;
            nextToke.lineNum = 0;
            nextToke.gItem = DUMMY;
            nextToke.intVal = 0;
            nextToke.floatVal = 0.0;
            toks1[cnt1-1] = nextToke;
            initializeParser(toks1,cnt1);
            initialiseParseHelpers();
            treeNodePtr tree = createParseTree(inputTestCaseFile);
            //printf("Printing Parse Tree\n\n");
           // printParser(tree);
            //printParseTree(tree, outputParseTreeFile);
            printf("--------------------------------------PRINTING SYMBOL TABLE----------------------------------\n");
            astNode* ast = makeAST(-1,-1,tree, NULL,NULL);
            populateSymbolTable(ast);
            printModuleSizes();
        /*
Activation record size

For printing the total memory requirement (sum total of widths of all variables in the function scope) for each function. The format is as follows 

-function1 18
-compute_sum 34

and so on
        */
            break;
        }
        case 7:{
            initialiselexer(inputTestCaseFile,bufSize);
            token currToke;
            int cnt1 = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                cnt1++;
            }
            cnt1++;
            initialiselexer(inputTestCaseFile,bufSize);
            token* toks1  = (token*)malloc(sizeof(token)*cnt1);
            int k = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                toks1[k] = currToke;
                k++;
            }
            token nextToke;
            nextToke.lexeme = NULL;
            nextToke.lineNum = 0;
            nextToke.gItem = DUMMY;
            nextToke.intVal = 0;
            nextToke.floatVal = 0.0;
            toks1[cnt1-1] = nextToke;
            initializeParser(toks1,cnt1);
            initialiseParseHelpers();
            treeNodePtr tree = createParseTree(inputTestCaseFile);
            //printf("Printing Parse Tree\n\n");
           // printParser(tree);
            //printParseTree(tree, outputParseTreeFile);
            printf("--------------------------------------PRINTING SYMBOL TABLE----------------------------------\n");
            astNode* ast = makeAST(-1,-1,tree, NULL,NULL);
            populateSymbolTable(ast);
            printArrays();
        //Errors reporting and total compile time
            break;
        }

        case 8:{
            initialiselexer(inputTestCaseFile,bufSize);
            token currToke;
            int cnt1 = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                cnt1++;
            }
            cnt1++;
            initialiselexer(inputTestCaseFile,bufSize);
            token* toks1  = (token*)malloc(sizeof(token)*cnt1);
            int k = 0;
            while(!finishedReading){
                currToke = getNextToken(fp);
                if((currToke.gItem == 0) || (currToke.gItem == COMMENT)) {
                    continue;
                }
                toks1[k] = currToke;
                k++;
            }
            token nextToke;
            nextToke.lexeme = NULL;
            nextToke.lineNum = 0;
            nextToke.gItem = DUMMY;
            nextToke.intVal = 0;
            nextToke.floatVal = 0.0;
            toks1[cnt1-1] = nextToke;
            initializeParser(toks1,cnt1);
            initialiseParseHelpers();
            treeNodePtr tree = createParseTree(inputTestCaseFile);
            //printf("Printing Parse Tree\n\n");
           // printParser(tree);
            //printParseTree(tree, outputParseTreeFile);
            printf("--------------------------------------PRINTING SYMBOL TABLE----------------------------------\n");
            astNode* ast = makeAST(-1,-1,tree, NULL,NULL);
            populateSymbolTable(ast);
        //Errors reporting and total compile time
            break;
        }

        case 9:
        //Code generation
            break;
        default:
            break;
        }
        /*
For printing the type expressions and width of array variables in a line for a test case for the following information. Separate entries using formatted output (e.g.  %10d, %15.4f and so on )

        */
}