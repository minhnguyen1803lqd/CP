#!/usr/bin/env python
import os
import sys

absoluteTemplatesPath = "/mnt/c/users/nguye/code/cp/templates"
absoluteUserPath = "/mnt/c/users/nguye/code/cp/judserver/users"
absoluteTestPath = "/mnt/c/users/nguye/code/cp/judserver/tests"
absolutePath = os.getcwd()

def makeFunc(cmd):
    if (cmd[1] != "make"):
        print("error input!")
        quit()
    name = cmd[2]
    if (os.path.exists(absolutePath + "/" + name)): # check whether the directory is exist
        print("folder exist") # log
        quit() # shutdown the program
    else:
        os.mkdir(absolutePath + "/" + name) # create a folder for the problems
        templatesFiles = os.listdir(absoluteTemplatesPath)  # read all the file in templates
        for file in templatesFiles:
            if (file == "task.cpp"):
                code = "cp " + absoluteTemplatesPath + "/" + file + " " + absolutePath + "/" + name + "/" + name + ".cpp"
            elif (file == "task.inp"):
                code = "cp " + absoluteTemplatesPath + "/" + file + " " + absolutePath + "/" + name + "/" + name + ".inp"
            else:
                code = "cp " + absoluteTemplatesPath + "/" + file + " " + absolutePath + "/" + name
            os.popen(code)
        print("task finish!")

def uploadFunc(cmd):
    if (cmd[1] != "upload"):
        print("errot input!")
        quit()
    user = cmd[2]
    problem = cmd[3]
    if (os.path.exists(absolutePath + "/" + problem) == False):
        print("directory: ", absolutePath + "/" + problem)
        print("directory doesn't exist!")
        quit()
    code = "cp " + absolutePath + "/" + problem + "/" + problem + ".cpp " + absoluteUserPath + "/" + user;
    os.popen(code)
    print("task finish!")

def generateFunc(cmd):
    if (cmd[1] != "generate"):
        print("error input")
        quit()
    name = cmd[2]
    query = cmd[3]
    path = os.getcwd() + "/" + name
    if (os.path.exists(path) == False):
        print("directory: ", path, " doesn't exist")
        quit()
    path = path + "/[test]" + name
    if (os.path.exists(path)):
        os.popen("rm -r " + path)
    os.mkdir(path)
    os.popen("g++ " + name + "/bruce.cpp -o " + name + "/bruce")
    os.popen("g++ " + name + "/generater.cpp -o " + name + "/generater")
    for i in range(0, int(query)):
        subPath = path + "/test"
        if (i < 10):
            subPath = subPath + "0"
        subPath = subPath + str(i)
        os.mkdir(subPath)
        os.popen("./" + name + "/generater")
        os.popen("./" + name + "/bruce")
        os.popen("mv " + name + ".ans " + subPath + "/" + name + ".out")
        os.popen("mv " + name + ".inp " + subPath)
    if (os.path.exists(absoluteTestPath + "/" + name)):
        os.popen("rm -r " + absoluteTestPath + "/" + name)
    os.popen("cp -r " + path + " " + absoluteTestPath + "/" + name)
    print("task finish!")

cmd = sys.argv
if (cmd[1] == "make"):
    makeFunc(cmd)
elif (cmd[1] == "upload"):
    uploadFunc(cmd)
elif (cmd[1] == "generate"):
    generateFunc(cmd)
`