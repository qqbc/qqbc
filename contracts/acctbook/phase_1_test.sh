echo "\n******************* Accounting Kata phase 1 testing  **********************\n"
echo "\n******************* setup account and category -- (unlock wallet) **********************\n"
cleos wallet unlock -n kata_1 --password PW5KDRk45HEVQLQFa2SQoSXXp2gFyiDXYPXfdGJhFVCQjGciWZPbY
time sleep 0.5
echo "\n******************* setup account and category -- (positive cases) **********************\n"
cleos push action acctbook addacct '["alice", "test1"]' -p alice@active
cleos push action acctbook addacct '["alice", "test2"]' -p alice@active
cleos push action acctbook addcat '["alice", "test1", "rent"]' -p alice@active
cleos push action acctbook addcat '["alice", "test1", "vacation"]' -p alice@active
cleos push action acctbook addcat '["alice", "test2", "rent"]' -p alice@active

time sleep 0.5
echo "\n******************* setup account and category -- (negative cases) **********************\n"
cleos push action acctbook addacct '["alice", "test1"]' -p alice@active
cleos push action acctbook addcat '["alice", "invalid", "rent"]' -p alice@active
cleos push action acctbook addcat '["alice", "test1", "rent"]' -p alice@active
cleos push action acctbook addcat '["alice", "test1", "rent#$%"]' -p alice@active

time sleep 0.5
echo "\n******************* setup account and category -- (summary) **********************\n"
cleos push action acctbook printacct '["alice", "test1"]' -p alice@active
cleos push action acctbook printacct '["alice", "test2"]' -p alice@active

time sleep 0.5
echo "\n******************* assign fund -- (positive cases) **********************\n"
cleos push action acctbook assignfund '["alice", "test1", 567.890]' -p alice@active
cleos push action acctbook assignfund '["alice", "test2", 987.654]' -p alice@active

time sleep 0.5
echo "\n******************* assign fund -- (negative cases) **********************\n"
cleos push action acctbook assignfund '["alice", "test1", -12345.6789]' -p alice@active
cleos push action acctbook assignfund '["alice", "invalid", 123.456]' -p alice@active

time sleep 0.5
echo "\n******************* assign fund -- (summary) **********************\n"
cleos push action acctbook printacct '["alice", "test1"]' -p alice@active
cleos push action acctbook printacct '["alice", "test2"]' -p alice@active

time sleep 0.5
echo "\n******************* transfer fund -- (positive cases) **********************\n"
cleos push action acctbook transfund '["alice", "test1", "default", "test1", "vacation", 123.456]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "default", "test1", "rent", 234.567]' -p alice@active
cleos push action acctbook transfund '["alice", "test2", "default", "test2", "rent", 345.678]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "rent", "test1", "vacation", 10.123]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "rent", "test1", "vacation", -5.123]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "rent", "test2", "rent", 20.234]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "rent", "test2", "rent", -5.345]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "vacation", "test2", "rent", 30.789]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "vacation", "test2", "rent", -8.765]' -p alice@active

time sleep 0.5
echo "\n******************* transfer fund -- (negative cases) **********************\n"
cleos push action acctbook transfund '["alice", "test1", "rent", "test1", "rent", 100]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "rent", "invalid", "rent", 100]' -p alice@active
time sleep 0.1
cleos push action acctbook transfund '["alice", "test1", "invalid", "test1", "rent", 100]' -p alice@active
cleos push action acctbook transfund '["alice", "invalid", "rent", "test1", "rent", 100]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "rent", "invalid", "rent", 100]' -p alice@active
# over balance
time sleep 0.1
cleos push action acctbook transfund '["alice", "test1", "vacation", "test1", "rent", 100000]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "rent", "test2", "rent", 100000]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "vacation", "test1", "rent", -100000]' -p alice@active
cleos push action acctbook transfund '["alice", "test1", "rent", "test2", "rent", -100000]' -p alice@active

time sleep 0.5
echo "\n******************* assign fund -- (summary) **********************\n"
time sleep 0.5
cleos push action acctbook printacct '["alice", "test1"]' -p alice@active
cleos push action acctbook printacct '["alice", "test2"]' -p alice@active
