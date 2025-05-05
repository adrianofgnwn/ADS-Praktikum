clear;clc;close all;

fid=fopen('quicksort2.txt');
 data=textscan(fid,'%d %f');
 fclose(fid);
 x=data{1};
 quicksort2_y=data{2};

 fid=fopen('insertionsort.txt');
 data=textscan(fid,'%d %f');
 fclose(fid);
 insertionsort_y=data{2};

 figure;
 title('sorting algorithms');
 xlabel('n [-]');
 ylabel('t [s]');
 hold on;
 plot(x,quicksort2_y);
 plot(x,insertionsort_y);

 legend('quicksort2','insertionsort');
 hold off;