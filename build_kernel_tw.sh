#!/bin/sh
export KERNELDIR=`readlink -f .`
export RAMFS_SOURCE="/home/googy/Anas/Googy-Max4-Kernel/Ramdisks/ramfs_tw"
export PARENT_DIR=`readlink -f ..`
export USE_SEC_FIPS_MODE=true
export CROSS_COMPILE=/home/googy/Anas/linaro_a15_4.9.3-2015.02/bin/arm-cortex_a15-linux-gnueabihf-

# if [ "${1}" != "" ];then
#  export KERNELDIR=`readlink -f ${1}`
# fi

RAMFS_TMP="/home/googy/Anas/Googy-Max4-Kernel/tmp_tw/ramfs"

VER="\"-GoogyMax4_TW-v$1\""
cp -f /home/googy/Anas/Googy-Max4-Kernel/Kernel/arch/arm/configs/0googymax4_TW_defconfig /home/googy/Anas/Googy-Max4-Kernel/0googymax4_TW_defconfig
sed "s#^CONFIG_LOCALVERSION=.*#CONFIG_LOCALVERSION=$VER#" /home/googy/Anas/Googy-Max4-Kernel/0googymax4_TW_defconfig > /home/googy/Anas/Googy-Max4-Kernel/Kernel/arch/arm/configs/0googymax4_TW_defconfig

# 
make 0googymax4_TW_defconfig VARIANT_DEFCONFIG=msm8974pro_sec_klte_eur_defconfig SELINUX_DEFCONFIG=selinux_defconfig || exit 1

. $KERNELDIR/.config

export KCONFIG_NOTIMESTAMP=true
export ARCH=arm

cd $KERNELDIR/
make -j3 CONFIG_NO_ERROR_ON_MISMATCH=y || exit 1

#remove previous ramfs files
rm -rf $RAMFS_TMP
rm -rf $RAMFS_TMP.cpio
rm -rf $RAMFS_TMP.cpio.gz
rm -rf $RAMFS_TMP/*
#copy ramfs files to tmp directory
cp -ax $RAMFS_SOURCE $RAMFS_TMP
#clear git repositories in ramfs
find $RAMFS_TMP -name .git -exec rm -rf {} \;
#remove orig backup files
# find $RAMFS_TMP -name .orig -exec rm -rf {} \;
#remove empty directory placeholders
find $RAMFS_TMP -name EMPTY_DIRECTORY -exec rm -rf {} \;
#remove mercurial repository
rm -rf $RAMFS_TMP/.hg
#copy modules into ramfs
mkdir -p /home/googy/Anas/Googy-Max4-Kernel/GT-I9505_GoogyMax4_TW5.CWM/system/lib/modules
rm -rf /home/googy/Anas/Googy-Max4-Kernel/GT-I9505_GoogyMax4_TW5.CWM/system/lib/modules/*
find -name '*.ko' -exec cp -av {} /home/googy/Anas/Googy-Max4-Kernel/GT-I9505_GoogyMax4_TW5.CWM/system/lib/modules/ \;
${CROSS_COMPILE}strip --strip-unneeded /home/googy/Anas/Googy-Max4-Kernel/GT-I9505_GoogyMax4_TW5.CWM/system/lib/modules/*

cd $RAMFS_TMP
find | fakeroot cpio -H newc -o > $RAMFS_TMP.cpio 2>/dev/null
ls -lh $RAMFS_TMP.cpio
gzip -9 $RAMFS_TMP.cpio
cd -

tools/dtbTool -o arch/arm/boot/dt.img -s 2048 -p scripts/dtc/ arch/arm/boot/
chmod a+r arch/arm/boot/dt.img
tools/mkbootimg --cmdline 'console=null androidboot.hardware=qcom user_debug=23 msm_rtb.filter=0x37 ehci-hcd.park=3 androidboot.selinux=permissive' --kernel $KERNELDIR/arch/arm/boot/zImage --ramdisk $RAMFS_TMP.cpio.gz --base 0x00000000 --pagesize 2048 --ramdisk_offset 0x02000000 --tags_offset 0x01E00000 --dt arch/arm/boot/dt.img --output $KERNELDIR/boot.img 		



cd /home/googy/Anas/Googy-Max4-Kernel
mv -f -v /home/googy/Anas/Googy-Max4-Kernel/Kernel/boot.img /home/googy/Anas/Googy-Max4-Kernel/GT-I9505_GoogyMax4_TW5.CWM/boot.img
cd /home/googy/Anas/Googy-Max4-Kernel/GT-I9505_GoogyMax4_TW5.CWM
zip -r ../GoogyMax4_TW5-Kernel_${1}_CWM.zip .

adb push /home/googy/Anas/Googy-Max4-Kernel/GoogyMax4_TW5-Kernel_${1}_CWM.zip /storage/sdcard0/GoogyMax4_TW5-Kernel_${1}_CWM.zip

# adb push /home/googy/Anas/Googy-Max4-Kernel/GoogyMax4_TW-Kernel_${1}_CWM.zip /storage/sdcard0/update-gmax4.zip
# 
# adb shell su -c "echo 'boot-recovery ' > /cache/recovery/command"
# adb shell su -c "echo '--update_package=/storage/sdcard0/update-gmax4.zip' >> /cache/recovery/command"
# adb shell su -c "reboot recovery"
