while true; do
    if ! ln file file.lock
    #if there is a file with name "file.lock" then sleep 1
    then
       sleep 1
    else
        #if there is no such a file then do the following
        #make file.lock file
        touch file.lock
        #then 50 times take the last number from the "file" and
        #increase it by one and append to the same file
        for i in {1..50}
        do
          #taking the last number(from the tail)
            n=$(tail -1 file)
            #increase it by 1
            ((n += 1))
            #write it on the end of the file
            echo $n >> file
        done
        #remove file.lock file
        rm file.lock
        break
    fi
done
#without
