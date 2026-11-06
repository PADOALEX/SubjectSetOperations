import subprocess
import sys

def run(text):
    return subprocess.run([sys.argv[1]],input=text.encode(),capture_output=True,timeout=3,check=True).stdout.decode('utf-8')

assert run('')
assert run('2\na\ninvalid\n')
output=run('2\na\n0\n1\n-1\n2\nb\n1\n2\n-1\n5\na\nb\nu\n6\na\nb\ni\n7\na\nb\ns\n4\n0\n')
assert 'u (3' in output and 'i (1' in output and 's (2' in output
print('PASS: union, intersection, symmetric difference and invalid/EOF input')
