#!/bin/bash
# install phpredis extension.

set -e

git clone https://github.com/phpredis/phpredis

cd phpredis
phpize
./configure
make
sudo make install

echo "extension=redis.so" > redis.ini
phpenv config-add redis.ini

