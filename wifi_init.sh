#!/bin/bash

connmanctl
enable wifi
scan wifi
sleep 2
agent on
session on
sleep 1
connect wifi_506583d914e3_hidden_managed_psk
sleep 1