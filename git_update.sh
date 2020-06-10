#!/bin/bash
git add -A
echo "Git commit purpose"
read data
git commit -m "$data"
git push -u
