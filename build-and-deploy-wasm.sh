#!/usr/bin/env bash
./fips build wasm-make-release
rm -rf ../fips-deploy/sova-test-app/wasm-make-release/content
cp -R content ../fips-deploy/sova-test-app/wasm-make-release/content
xdg-open http://localhost:3000/sova-test-app.html &