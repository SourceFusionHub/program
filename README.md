Simple Recommendation library for Redis and PHP
=============================

[![Coverage Status](https://coveralls.io/repos/github/YuzuruS/redis-recommend/badge.svg?branch=master)](https://coveralls.io/github/YuzuruS/redis-recommend?branch=master)
[![Build Status](https://travis-ci.org/YuzuruS/redis-recommend.png?branch=master)](https://travis-ci.org/YuzuruS/redis-recommend)
[![Stable Version](https://poser.pugx.org/yuzuru-s/redis-recommend/v/stable)](https://packagist.org/packages/yuzuru-s/redis-recommend)
[![Download Count](https://poser.pugx.org/yuzuru-s/redis-recommend/downloads.png)](https://packagist.org/packages/yuzuru-s/redis-recommend)
[![License](https://poser.pugx.org/yuzuru-s/redis-recommend/license)](https://packagist.org/packages/yuzuru-s/redis-recommend)

Abstracting Redis's `Sorted Set` APIs and PHP to use as a recommending system.  
This Recommendation algorithm use `Collaborative Filtering`, especially [Jaccard coefficient](https://en.wikipedia.org/wiki/Jaccard_index)

This Recommendation algorithm is used by [Amazon.com](https://www.amazon.com/)

![Amazon](https://cloud.githubusercontent.com/assets/1485195/17956534/72ca4d3a-6ac5-11e6-985e-9074251b5f35.jpg)


Please check [here](http://qiita.com/yudsuzuk/items/6de4650cb6d50236533e) for details.

Requirements
-----------------------------
- Redis
  - >=2.4
- PhpRedis extension
  - https://github.com/nicolasff/phpredis
- PHP
  - >=5.5 >=5.6, >=7.0, >=7.1, >= 7.2
- Composer



Installation
----------------------------

* Using composer

```
{
    "require": {
       "yuzuru-s/redis-recommend": "1.0.*"
    }
}
```

```
$ php composer.phar update yuzuru-s/redis-recommend --dev
```

How to use
----------------------------
Please check [sample code](https://github.com/YuzuruS/redis-recommend/blob/master/sample/usecase.php)


How to run unit test
----------------------------

Run with default setting.
```
% vendor/bin/phpunit -c phpunit.xml.dist
```

Currently tested with PHP 7.2.0 + Redis 2.6.12.


History
----------------------------
- 1.0.10
  - support php7.2
- 1.0.9
  - unsupport HHVM
- 1.0.8
  - support HHVM
- 1.0.7
  - support php7.1
- 1.0.6
  - bug fix
- 1.0.5
  - supports travis CI and passed test and display code coverage.
- 1.0.0
  - Published



License
----------------------------
Copyright (c) 2017 YUZURU SUZUKI. See MIT-LICENSE for further details.

Copyright
-----------------------------
- Yuzuru Suzuki
  - http://yuzurus.hatenablog.jp/
