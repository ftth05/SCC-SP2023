#!/bin/bash
#SBATCH -N 1 -n 1 -J tf1n_job       # job name
#SBATCH  -o result.o%j       # output and error file name (%j expands to jobID)
#SBATCH --time=00:3:00 ## -p gpu --gres=gpu:2         # run time (hh:mm:ss) - 1.5 hours
#SBATCH --mail-user=jebalunode@uh.edu
#SBATCH --mail-type=all    # email me when the job finishes

./passValue1  34 35
