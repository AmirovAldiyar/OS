while true; do
    if ! ln file file.lock
    then
       sleep 1
    else
        touch file.lock
        for i in {1..50}
        do
            ((count += 1))
            n=$(tail -1 file)
            ((n += 1))
            echo $n >> file
        done
        rm file.lock
        break
    fi
done
