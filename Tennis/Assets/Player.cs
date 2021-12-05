using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public Transform aimTarget; // the target where we aim to land the ball
    float speed = 3f; // move speed
    float force = 10; // ball impact force
    Vector3 targetPosition; // position to where the bot will want to move

    bool hitting = false; // boolean to know if we are hitting the ball or not 

    public Transform ball; // the ball 
    Animator animator;

    Vector3 aimTargetInitialPosition; // initial position of the aiming gameObject which is the center of the opposite court

    ShotManager shotManager; // reference to the shotmanager component
    Shot currentShot; // the current shot we are playing to acces it's attributes

    private void Start()
    {
        animator = GetComponent<Animator>(); // referennce out animator
        aimTargetInitialPosition = aimTarget.position; // initialise the aim position to the center( where we placed it in the editor )
        targetPosition = transform.position; // initialize the targetPosition to its initial position in the court
        shotManager = GetComponent<ShotManager>(); // accesing our shot manager component 
        currentShot = shotManager.topSpin; // defaulting our current shot as topspin
    }

    void Update()
    {
        float h = Input.GetAxisRaw("Horizontal"); // get the horizontal axis of the keyboard
        float v = Input.GetAxisRaw("Vertical"); // get the vertical axis of the keyboard

        if (Input.GetKeyDown("space"))
        {
            hitting = true; // we are trying to hit the ball and aim where to make it land
        }


        if (hitting)  // if we are trying to hit the ball
        {
            aimTarget.Translate(new Vector3(h, 0, 0) * speed * 2 * Time.deltaTime); //translate the aiming gameObject on the court horizontallly
        }

        Vector3 ballDir = ball.position - transform.position;       // get the position of the ball compared to us
        if (ballDir.x >= 1)                                         // update the target position to the ball's x position so the bot only moves on the x axis
        {
            targetPosition.x = ball.position.x - 1;
        }
        else if (ballDir.x >= -1)
        {
            targetPosition.x = transform.position.x;
        }
        else
        {
            targetPosition.x = ball.position.x + 1;
        }
        transform.position = Vector3.MoveTowards(transform.position, targetPosition, speed * Time.deltaTime); // lerp it's position

    }


    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Ball")) // if we collide with the ball 
        {
            int randomValue = Random.Range(-3, 4);
            if (randomValue < 0)
            {
                currentShot = shotManager.topSpin; // set our current shot to top spin
            } else
            {
                currentShot = shotManager.flat;
            }
            Vector3 dir = aimTarget.position - transform.position + new Vector3(randomValue, 0, 0); // get the direction to where we want to send the ball
            other.GetComponent<Rigidbody>().velocity = dir.normalized * currentShot.hitForce + new Vector3(0, currentShot.upForce, 0);
            //add force to the ball plus some upward force according to the shot being played

            Vector3 ballDir = ball.position - transform.position; // get the direction of the ball compared to us to know if it is
            if (ballDir.x >= 0)                                   // on out right or left side 
            {
                animator.Play("forehand");                        // play a forhand animation if the ball is on our right
            }
            else                                                  // otherwise play a backhand animation 
            {
                animator.Play("backhand");
            }

            aimTarget.position = aimTargetInitialPosition; // reset the position of the aiming gameObject to it's original position ( center)
        }
    }


}