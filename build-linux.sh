#!/usr/bin/env bash
./fips build linux-make-debug
rm -rf ../fips-deploy/sova-test-app/content
cp -R content ../fips-deploy/sova-test-app/content