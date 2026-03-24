import sys
import os
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.stdin=open(os.path.join(script_dir, "dwarf.inp"),"r")
sys.stdout=open(os.path.join(script_dir, "dwarf.out"),"w")
n=int(input())
print(n)