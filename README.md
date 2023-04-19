# IA_Rover_project2020
The IA Rover project is a project done in 2020 as a student

The initial purpose was to put a camera on a little vehicle such as a remote control car.
Then, place a target (black concentric circle in our case), and make the rover detect (using IA) and follow the target.


As a group project, my work was based on the first task (only my part will be published on git).


It consists of providing a dataset to train an IA on the cascade model using openCV.
Then, use the parameter given by the training to detect the target on live using a camera on a raspberry pi.


We can divide this goal in 3 subtasks : 

- Create a dataset from image-net.org and your photo, then preparing and cleaning it for training. (create a positive image then generate a dataset using this positive image)

- Train the IA with the cascade model using openCV and gather the parameter xml file (weights of the neural network).

- provide the parameter file to a program that reads a camera on a raspberry pi and give the location and size of the target on the image as a form of rectangle (see result video).


The result are overall pretty correct. As the target is very simple, some elementary shape can be confounded with the real target (example on video 2).

I display the results on youtube.
[![Result:](https://img.youtube.com/vi/s6oeftHc4Rc/default.jpg)](https://www.youtube.com/watch?v=s6oeftHc4Rc)

The following of the project can be easily done by writing a program that control the motor of the robot knowing the position of the target on the image.


The dataset_preparation folder contains only one src code that take all the files from an input folder (contains all the images with different names)

The image list was download from https://www.image-net.org. It gives a list of url in a file you can use to download all the images with a simple python script (I was not able to find it again). Then, we transform them in black and white, resize them and rename them by growing number.

The dataset_training_content's folder contain the data prepared for training (neg) and the output repository (data) with final parameters in the cascade.xml file.

opencv folder is used for the cascade classifier.
vec files give the coordinate of the target in the image used for training and calculate the cost function.
The first number (1 or 2) shows wich target image we used (cible1 or cible2 in the posDirCible folder).
The two other numbers show the size of the image (5050 means 50px width by 50px high for example).

The live detection folder need to be setup on the raspberry pi with the opencv library. It reads the frame coming from the camera and use the parameter xml file to do a forward propagation and detect were the targets are in the image (coordinate and size).

The output is a list of rectangles. Some file such as lisseur.cpp are empty as the project wasn't finish.
The library of opencv need to be install. And a Linux environment is preferable to train the dataset with opencv.


The result is displayed in four videos with different lighting and place (video folder).
